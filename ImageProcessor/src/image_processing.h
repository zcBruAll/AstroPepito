#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <string>
#include <opencv2/opencv.hpp>

enum class ColorMode {
    Grayscale,
    ColorMapped,
    Composite
};

void processImage(const std::string& filePath, ColorMode mode);

void processImage(const std::string& layer1Path,
                  const std::string& layer2Path,
                  const std::string& layer3Path);

void processColorComposite(const std::string& layer1Path,
                           const std::string& layer2Path,
                           const std::string& layer3Path);

cv::Mat loadFITSImage(const std::string& filePath);

#endif
