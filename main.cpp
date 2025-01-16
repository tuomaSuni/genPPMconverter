#include <iostream>
#include <fstream>

using namespace std;

// Define the image dimensions
const int WIDTH = 256;
const int HEIGHT = 256;

// Function to create a simple PPM file
void generatePPM(const string& filename) {
    ofstream outFile(filename, ios::binary);

    if (!outFile) {
        cerr << "Error: Unable to create file!" << endl;
        return;
    }

    // Write the PPM header
    outFile << "P6\n";              // PPM type (binary format)
    outFile << WIDTH << " " << HEIGHT << "\n"; // Image dimensions
    outFile << "255\n";             // Max color value

    // Write pixel data (in this case, a gradient from red to blue)
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            unsigned char red = (unsigned char)(255 * (x / (float)WIDTH)); // Red gradient
            unsigned char green = 0;                                       // No green
            unsigned char blue = (unsigned char)(255 * (y / (float)HEIGHT)); // Blue gradient

            outFile.put(red);
            outFile.put(green);
            outFile.put(blue);
        }
    }

    outFile.close();
    cout << "PPM file generated successfully!" << endl;
}

int main() {
    string filename = "output.ppm"; // Output file name
    generatePPM(filename);          // Generate PPM image
    return 0;
}