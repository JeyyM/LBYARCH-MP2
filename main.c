#include <stdio.h>
#include <stdlib.h>

// note unsigned char is the uint8 requirement which is 0 to 255
extern void imgCvtGrayDoubleToInt(int height, int width, double* floatPixels, unsigned char* intPixels);

int main() {
    printf("=== Grayscale Image Conversion: Double to UInt8 ===\n");
    printf("Formula: i = f * 255\n\n");
    
    int height = 3;
    int width = 4;
    int totalPixels = height * width;
    
    double floatPixels[] = {
        0.25, 0.35, 0.45, 0.33,
        0.55, 0.65, 0.75, 0.33,
        0.85, 0.95, 0.15, 0.33
    };
    
    unsigned char intPixels[12];
    
    printf("Input (3x4 image - double float values):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", floatPixels[i * width + j]);
        }
        printf("\n");
    }
    printf("\n");
    
    imgCvtGrayDoubleToInt(height, width, floatPixels, intPixels);
    
    printf("Output (3x4 image - uint8 values):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3u ", intPixels[i * width + j]);
        }
        printf("\n");
    }
    
    return 0;
}
