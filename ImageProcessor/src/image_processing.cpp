#include <opencv2/opencv.hpp>   // OpenCV library for image processing
#include <fitsio.h>             // CFITSIO library for handling FITS files
#include <iostream>             // Standard library for input and output
#include <vector>               // Standard library container for handling dynamic arrays
#include "image_processing.h"   // Header file for declaring the processImage function

void processImage(const std::string& filePath, ColorMode mode) {
    cv::Mat image = loadFITSImage(filePath);

    if (image.empty()) {
        std::cout << "image is empty." << std::endl;
        return;
    }

    if (mode == ColorMode::ColorMapped) {
        // Apply color map if ColorMapped mode is chosen
        cv::Mat colorImage;
        cv::applyColorMap(image, colorImage, cv::COLORMAP_INFERNO);
        cv::imwrite("color_output_image.png", colorImage);
        std::cout << "Image saved as color_output_image.png with a color map." << std::endl;
    } else {
        // Save the processed image to a file in PNG format
        cv::imwrite("output_image.png", image);

        // Log a success message to confirm that the image was saved
        std::cout << "Image saved as output_image.png" << std::endl;
    }
}

// Function to process and save an image based on a FITS file
void processImage(const std::string& layer1Path,
                  const std::string& layer2Path,
                  const std::string& layer3Path) {
    // Check if the rgb files are missing to prevent processing with nothing
    if (layer1Path.empty() || layer2Path.empty() || layer3Path.empty()) {
        std::cerr << "Error: Composite mode requires paths to red, green and red FITS file." << std::endl;
        return;
    }
    processColorComposite(layer1Path, layer2Path, layer3Path);
}

void processColorComposite(const std::string& layer1Path, const std::string& layer2Path, const std::string& layer3Path) {
    // TODO
}

// Helper function to load FITS images as an OPENCV Mat
cv::Mat loadFITSImage(const std::string& filePath) {
    fitsfile* fptr;             // FITS file pointer, used by CFITSIO to reference the open file
    int status = 0;             // Status variable for CFITSIO; 0 means no error

    // Attempt to open the FITS file in read-only mode
    if (fits_open_file(&fptr, filePath.c_str(), READONLY, &status)) {
        // If opening the file fails, CFITSIO provides an error message
        fits_report_error(stderr, status);  
        return cv::Mat();  // Exit the function if the file couldn't be opened
    }

    int naxis = 0;              // Number of dimensions in the FITS image
    long naxes[2] = {1, 1};     // Array to hold the width (naxes[0]) and height (naxes[1]) of the image

    // Get the dimensions of the image from the FITS header
    // `fits_get_img_dim` gets the number of dimensions (naxis), which should be 2 for a 2D image
    // `fits_get_img_size` retrieves the width and height and stores them in the `naxes` array
    if (fits_get_img_dim(fptr, &naxis, &status) || fits_get_img_size(fptr, 2, naxes, &status)) {
        // Report an error if retrieving dimensions fails
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);  // Close the file before exiting
        return cv::Mat();
    }

    // Calculate the total number of pixels in the image by multiplying width by height
    long numPixels = naxes[0] * naxes[1];

    // Create a vector to hold the pixel values; using `float` since FITS files often use floating-point precision
    std::vector<float> pixels(numPixels);

    // Read the image data from the FITS file into the `pixels` vector
    // `TFLOAT` specifies that the data should be read as floats
    // `1` specifies the starting pixel (beginning of the image)
    if (fits_read_img(fptr, TFLOAT, 1, numPixels, NULL, pixels.data(), NULL, &status)) {
        // Report an error if reading the image data fails
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);  // Close the file before exiting
        return cv::Mat();
    }

    // Close the FITS file after successfully reading the image data
    fits_close_file(fptr, &status);

    // Convert the FITS data to an OpenCV Mat object for processing and display
    // OpenCV Mat uses a 2D format with height (rows) and width (cols), so we set naxes[1] (height) and naxes[0] (width)
    cv::Mat image(naxes[1], naxes[0], CV_32F, pixels.data());

    // Normalize the image data for better visualization
    // `cv::normalize` scales the pixel values to the 0–255 range for display purposes
    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX);
    image.convertTo(image, CV_8U);  // Convert to 8-bit format (required for saving as PNG or JPEG)
    return image;
}