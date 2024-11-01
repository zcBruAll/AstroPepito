#include <iostream>             // Standard library for input and output
#include "hdu_inspector.h"   // Header file for declaring the processImage function

int main() {
    // file path to the directory of the FITS data files
    std::string fitsFileDir = "/mnt/f/AstroPepito/data/";

    // complete file path to the FITS data file to process
    std::string fitsFilePath = fitsFileDir + "f001a066.fits";

    std::cout << "Welcome to AstroPepito HDU Inspector!" << std::endl;

    printAllHDUObjects(fitsFilePath);

    return 0;
}
