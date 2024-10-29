project(ImageProcessor)

# Find OpenCV and CFITSIO
find_package(OpenCV REQUIRED)
find_library(CFITSIO_LIB cfitsio REQUIRED)

# Add the executable for Image Processor
add_executable(ImageProcessor src/main.cpp src/image_processing.cpp)

# Link libraries (OpenCV and CFITSIO) to the executable
target_link_libraries(ImageProcessor ${OpenCV_LIBS} ${CFITSIO_LIB})
