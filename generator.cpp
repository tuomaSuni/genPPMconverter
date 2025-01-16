#include <iostream>

const int IMAGE_WIDTH = 256;
const int IMAGE_HEIGHT = 256;
const int MAX_COLOR_VALUE = 255;

int calculateColorValue(double normalizedValue) {
    return static_cast<int>(MAX_COLOR_VALUE * normalizedValue);
}

int main() {

    std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n" << MAX_COLOR_VALUE << "\n";

    for (int j = 0; j < IMAGE_HEIGHT; ++j) {
        for (int i = 0; i < IMAGE_WIDTH; ++i) {

            double normalized_r = double(i) / (IMAGE_WIDTH - 1);
            double normalized_g = double(j) / (IMAGE_HEIGHT - 1);
            double normalized_b = 1.0;

            int r = calculateColorValue(normalized_r);
            int g = calculateColorValue(normalized_g);
            int b = calculateColorValue(normalized_b);
            
            std::cout << r << ' ' << g << ' ' << b << '\n';
        }
    }

    return 0;
}