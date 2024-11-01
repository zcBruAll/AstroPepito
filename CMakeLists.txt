cmake_minimum_required(VERSION 3.10)
project(AstroPepito VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the Image Processor module as a subdirectory
add_subdirectory(ImageProcessor)
add_subdirectory(HDUInspector)