#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define maxWidth 512
#define maxHeight 512

int crossingNumber(int x, int y, int **image) {
    int cn = 0; // Crossing number
    int p1, p2;

    // Loop through the 8 neighbors of the pixel (x, y)
    for (int k = 0; k < 8; k++) {
        // Get the coordinates of the current and next neighbor
        int x1 = x + (k % 3) - 1;
        int y1 = y + (k / 3) - 1;
        int x2 = x + ((k + 1) % 3) - 1;
        int y2 = y + ((k + 1) / 3) - 1;

        // Ensure the coordinates are within the image boundaries
        if (x1 >= 0 && x1 < maxWidth && y1 >= 0 && y1 < maxHeight &&
            x2 >= 0 && x2 < maxWidth && y2 >= 0 && y2 < maxHeight) {
            p1 = image[y1][x1];
            p2 = image[y2][x2];

            // Check for a crossing from 0 to 1
            if (p1 == 0 && p2 == 1) {
                cn++;
            }
        }
    }
    return cn;
}

void printResult(int **inResult) {
    for (int i = 0; i < maxHeight; i++) {
        for (int j = 0; j < maxWidth; j++) {
            printf("%d ", inResult[i][j]);
        }
        printf("\n");
    }
}

void freeMemory(int **inArray, int inRows) {
    for(int row=0;row<inRows;row++) {
        free(inArray[row]);
    }
    free(inArray);
}

int main() {
    int **image = (int **)malloc(maxHeight * sizeof(int *));
    int **result = (int **)malloc(maxHeight * sizeof(int *));
    if(image==NULL || result==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return EXIT_FAILURE;
    }
    for(int height=0;height<maxHeight;height++) {
        image[height] = (int *)malloc(maxWidth*sizeof(int));
        result[height] = (int *)malloc(maxWidth*sizeof(int));
        if(image[height]==NULL || result[height]==NULL) {
            fprintf(stderr,"Memory allocation failed.");
            return EXIT_FAILURE;
        }
    }

    for (int iter = 0; iter < maxHeight; iter++) {
        for (int jter = 0; jter < maxWidth; jter++) {
            image[iter][jter] = (iter + jter) % 2; // Sample initialization, alternating 0 and 1
        }
    }

    // double startSerialTime = omp_get_wtime();
    // for (int iter = 0; iter < maxHeight; iter++) {
    //     for (int jter = 0; jter < maxWidth; jter++) {
    //         result[iter][jter] = crossingNumber(iter, jter, image);
    //     }
    // }
    // double endSerialTime = omp_get_wtime();

    double startParallelTime = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int iter = 0; iter < maxHeight; iter++) {
        for (int jter = 0; jter < maxWidth; jter++) {
            result[iter][jter] = crossingNumber(iter, jter, image);
        }
    }
    double endParallelTime = omp_get_wtime();
    
    // printf("Serial Execution Time: %.5f",(endSerialTime-startSerialTime));
    printf("\nParallel Execution Time: %.5f",(endParallelTime-startParallelTime));
    
    // printResult(result);

    freeMemory(image, maxHeight);
    freeMemory(result, maxHeight);
    return EXIT_SUCCESS;
}
