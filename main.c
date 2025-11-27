#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// note unsigned char is the uint8 requirement which is 0 to 255
extern void imgCvtGrayDoubleToInt(int height, int width, double* floatPixels, unsigned char* intPixels);

int main() {
    int height = 3;
    int width = 4;
    int totalPixels = height * width;
    
    double floatPixels[] = {
        0.25, 0.35, 0.45, 0.33,
        0.55, 0.65, 0.75, 0.33,
        0.85, 0.95, 0.15, 0.33
    };
    
    unsigned char intPixels[12];
    
    printf("Input:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", floatPixels[i * width + j]);
        }
        printf("\n");
    }
    printf("\n");
    
    imgCvtGrayDoubleToInt(height, width, floatPixels, intPixels);
    
    printf("Output:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3u ", intPixels[i * width + j]);
        }
        printf("\n");
    }
    
    getchar();

    // 10x10 test

    height = 10;
    width = 10;
    totalPixels = height * width;
    double randFloatPixels[100];
    unsigned char randIntPixels[100];
    int runs = 30;
    double totalTime = 0.0;
    srand((unsigned int)time(NULL));

    for (int run = 0; run < runs; run++) {
        for (int i = 0; i < totalPixels; i++) {
            double val = (double)rand() / RAND_MAX;
            randFloatPixels[i] = ((int)(val * 100 + 0.5)) / 100.0;
        }
        clock_t start = clock();
        imgCvtGrayDoubleToInt(height, width, randFloatPixels, randIntPixels);
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        totalTime += elapsed;

        if (run == 0) {
            printf("\nFirst 10x10 input:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%.2f ", randFloatPixels[i * width + j]);
                }
                printf("\n");
            }
            printf("\nFirst 10x10 output:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%3u ", (unsigned char)randIntPixels[i * width + j]);
                }
                printf("\n");
            }
        }
    }
    printf("\nAverage time for 10x10: %.8f seconds per run\n", totalTime / runs);

    getchar();


    // 100x100 test
    height = 100;
    width = 100;
    totalPixels = height * width;
    double randFloatPixels100[10000];
    unsigned char randIntPixels100[10000];
    double totalTime100 = 0.0;

    for (int run = 0; run < runs; run++) {
        for (int i = 0; i < totalPixels; i++) {
            double val = (double)rand() / RAND_MAX;
            randFloatPixels100[i] = ((int)(val * 100 + 0.5)) / 100.0;
        }
        clock_t start = clock();
        imgCvtGrayDoubleToInt(height, width, randFloatPixels100, randIntPixels100);
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        totalTime100 += elapsed;

        if (run == 0) {
            printf("\nFirst 100x100 input:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%.2f ", randFloatPixels100[i * width + j]);
                }
                printf("\n");
            }
            printf("\nFirst 100x100 output:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%3u ", (unsigned char)randIntPixels100[i * width + j]);
                }
                printf("\n");
            }
        }
    }
    printf("\nAverage time for 100x100: %.8f seconds per run\n", totalTime100 / runs);

    getchar();

    // 460x460 test
    height = 460;
    width = 460;
    totalPixels = height * width;
    double randFloatPixels460[211600];
    unsigned char randIntPixels460[211600];
    double totalTime460 = 0.0;
    for (int run = 0; run < runs; run++) {
        for (int i = 0; i < totalPixels; i++) {
            double val = (double)rand() / RAND_MAX;
            randFloatPixels460[i] = ((int)(val * 100 + 0.5)) / 100.0;
        }
        clock_t start = clock();
        imgCvtGrayDoubleToInt(height, width, randFloatPixels460, randIntPixels460);
        clock_t end = clock();
        double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        totalTime460 += elapsed;

        if (run == 0) {
            printf("\nFirst 460x460 input:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%.2f ", randFloatPixels460[i * width + j]);
                }
                printf("\n");
            }
            printf("\nFirst 460x460 output:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%3u ", (unsigned char)randIntPixels460[i * width + j]);
                }
                printf("\n");
            }
        }
    }
    printf("\nAverage time for 460x460: %.8f seconds per run\n", totalTime460 / runs);
    return 0;

}
