#include <iostream>             // Standard library for input and output
#include "image_processing.h"   // Header file for declaring the processImage function

int main() {
    // file path to the directory of the FITS data files
    std::string fitsFileDir = "/mnt/f/AstroPepito/data/";

    // complete file path to the FITS data file to process
    std::string fitsFilePath = fitsFileDir + "f001/f001a066.fits";


    std::string redPath = fitsFileDir + "ngc7293/ngc7293_r.fits";
    std::string greenPath = fitsFileDir + "ngc7293/ngc7293_g.fits";
    std::string bluePath = fitsFileDir + "ngc7293/ngc7293_b.fits";
    std::string infraredPath = fitsFileDir + "ngc7293/ngc7293_l.fits";

    std::cout << "Welcome to AstroPepito Image Processor!" << std::endl;

    // Start of the image processing
    processImage(infraredPath, ColorMode::Grayscale);
    processImage(fitsFilePath, ColorMode::ColorMapped);
    processImage(redPath, greenPath, bluePath);

    return 0;
}
