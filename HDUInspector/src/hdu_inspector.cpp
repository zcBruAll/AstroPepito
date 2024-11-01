#include <opencv2/opencv.hpp>   // OpenCV library for image processing
#include <fitsio.h>             // CFITSIO library for handling FITS files
#include <iostream>             // Standard library for input and output
#include "hdu_inspector.h"   // Header file for declaring the processImage function

// Function to print all the 
void printAllHDUObjects(const std::string& filePath) {
    fitsfile* fptr;             // FITS file pointer, used by CFITSIO to reference the open file
    int status = 0;             // Status variable for CFITSIO; 0 means no error

    // Attempt to open the FITS file in read-only mode
    if (fits_open_file(&fptr, filePath.c_str(), READONLY, &status)) {
        // If opening the file fails, CFITSIO provides an error message
        fits_report_error(stderr, status);  
        return;  // Exit the function if the file couldn't be opened
    }

    int hduCount = 0;          // Number of HDU in the FITS file

    // Get the number of HDU in the FITS file
    if (fits_get_num_hdus(fptr, &hduCount, &status)) {
        // Report an error if retrieving numbers of HDUs fails
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);
        return;
    }

    std::cout << "Number of HDUs: " << hduCount << std::endl;

    // Iterate through each HDU
    for (int i = 1; i <= hduCount; i++) {
        if (fits_movabs_hdu(fptr, i, NULL, &status)) {
            fits_report_error(stderr, status);
            return;
        }

        char objectName[80];      // Name of the object of the FITS file
        // Get the object name of the FITS file
        // `fits_read_key` gets the value for the specified key
        if (fits_read_key(fptr, TSTRING, "OBJECT", objectName, NULL, &status)) {
            // If OBJECT keyword is missing, reset the status and set a default message
            status = 0;
            std::cout << "HDU " << i << ": OBJECT keyword not found." << std::endl;
        }
        else {
            std::cout << "HDU " << i << ": OBJECT = " << objectName << std::endl;
        }

        // Identify HDU type
        int hduType;
        if (fits_get_hdu_type(fptr, &hduType, &status)) {
            // Report an error if retrieving the hdu type fails
            fits_report_error(stderr, status);
            break;
        }

        switch (hduType)
        {
            case IMAGE_HDU:
                std::cout << " - HDU Type: Image" << std::endl;
                break;
            case BINARY_TBL:
                std::cout << " - HDU Type: Binary Table" << std::endl;
                break;
            case ASCII_TBL:
                std::cout << " - HDU Type: ASCII Table" << std::endl;
                break;
            default:
                std::cout << " - HDU Type: Unknown" << std::endl;
                break;
        }

        std::cout << "------------------------------" << std::endl;
    }
}