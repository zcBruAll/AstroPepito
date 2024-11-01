project(ImageProcessor)

# Find OpenCV and CFITSIO
find_package(OpenCV REQUIRED)
find_library(CFITSIO_LIB cfitsio REQUIRED)

# Add the executable for Image Processor
add_executable(HDUInspector src/main.cpp src/hdu_inspector.cpp)

# Link libraries (OpenCV and CFITSIO) to the executable
target_link_libraries(HDUInspector ${OpenCV_LIBS} ${CFITSIO_LIB})
