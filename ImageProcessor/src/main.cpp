#include <iostream>             // Standard library for input and output
#include "image_processing.h"   // Header file for declaring the processImage function

int main() {
    // file path to the directory of the FITS data files
    std::string fitsFileDir = "/mnt/f/AstroPepito/ImageProcessor/data/";

    // complete file path to the FITS data file to process
    std::string fitsFilePath = fitsFileDir + "f001a066.fits";

    std::cout << "Welcome to AstroPepito Image Processor!" << std::endl;

    // Start of the image processing
    processImage(fitsFilePath);

    return 0;
}
