# AstroPepito
This project is meant to group up multiples tools relateed to astronomy. 
Coded in C++, it's more like a fun project I work during my free time, it allows me to link my 2 passions: Development and Astronomy

## Installation
### Prerequisites
- An Linux environment (WSL works)
- Visual Studio Code

#### Setup in Visual Studio Code
Open VS Code and go to the Extension sidebar (or `Ctrl + Shift + X`)
Install the following extensions: 
- C/C++ by Microsoft
- CMake Tools
- Remote - WSL (If working with WSL)

#### Installing dependencies in the terminal
**Update packages:**
```bash
sudo apt update
```
**Install Essential Build Tools:**
```bash
sudo apt install build-essential
```
**Install CMake:**
```bash
sudo apt install cmake
```
**Install Librairies for FITS Handling and Image processing**
- **CFITSIO**: For handling FITS files
```bash
sudo apt install libcfitsio-dev
```
- **OpenCV**: For more advanced image processing
```bash
sudo apt install libopencv-dev
```

**Optional: Cloning the repository**
To start using AstroPepito, you can clone this repository and navigate into the directory:
```bash
git clone https://github.com/zcBruAll/AstroPepito.git
cd AstroPepito
```

## Usage
After cloning and setting up the project, follow these steps to build and run the project:
1. **Configure the Project with CMake**
In the project root, creeate a build directory and run CMake:
```bash
mkdir build
cd build
cmake ..
```
2. **Build the Project**
After configuring with CMake, build the project:
```bash
make
```
3. **Run the Program**
Execute the main program from the `build` directory. Example:
```bash
./ImageProcessor/ImageProcessor
```

### Example
To process a FITS file, place it in the `data/` directory (or specify a different path in `main.cpp`), then recompile and run. The program will generate an output image (e.g., `output_image.png`) based on the FITS file data.

## Project Structure
Here's a quick overview of the project structure:
```
AstroPepito/
├── CMakeLists.txt           # Root CMake file to manage all modules
├── ImageProcessor/          # Module for FITS file image processing
│   ├── src/                 # Source files
│   ├── data/                # FITS data files
│   ├── CMakeLists.txt       # CMake file for the Image Processor module
└── README.md                # Project documentation
```
## Future plans
AstroPepito is designed to grow over time. Here are some potential future features:
- **Exoplanet Detection**: Analyzing light curves for transit detection
- **Spectral Analysis**: Processing spectral data to identify elements and temperatures
- **3D Galaxy Mapping**: Creating a 3D visualizations of galaxy data