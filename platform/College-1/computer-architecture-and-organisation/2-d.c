#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxRows 3
#define maxCols 3

void printMemoryAllocFailed() {
    fprintf(stderr, "Memory Allocation failed.");
}

float **add2Matrix(float **matrix1, float **matrix2, int inRows, int inCols) {
    float **outMatrix = (float **)malloc(inRows*sizeof(float *));
    if (outMatrix == NULL) {
        printMemoryAllocFailed();
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < inRows; row++) {
        outMatrix[row] = (float *)calloc(inCols, sizeof(float));
        if (outMatrix[row] == NULL) {
            printMemoryAllocFailed();
            for (int i=0; i<row; i++) {
                free(outMatrix[i]);
            }
            free(outMatrix);
            exit(EXIT_FAILURE);
        }
    }

    for (int row=0; row<inRows; row++) {
        for (int col=0; col<inCols; col++) {
            outMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
    return outMatrix;
}

float **mul2Matrix(float **matrix1, int inRows1, int inCols1, float **matrix2, int inRows2, int inCols2, bool negative) {
    if (inCols1 != inRows2) {
        printf("Matrix multiplication not possible.");
        exit(EXIT_FAILURE);
    }

    float **outMatrix = (float **)malloc(inRows1 * sizeof(float *));
    if (outMatrix == NULL) {
        printMemoryAllocFailed();
        exit(EXIT_FAILURE);
    }

    for (int row=0; row<inRows1; row++) {
        outMatrix[row] = (float *)calloc(inCols2, sizeof(float));
        if (outMatrix[row] == NULL) {
            printMemoryAllocFailed();
            for (int i = 0; i < row; i++) {
                free(outMatrix[i]);
            }
            free(outMatrix);
            exit(EXIT_FAILURE);
        }
    }

    for (int iter=0; iter<inRows1; iter++) {
        for (int jter=0; jter<inCols2; jter++) {
            for (int kter = 0; kter < inCols1; kter++) {
                if (negative) {
                    outMatrix[iter][jter] = outMatrix[iter][jter] + (matrix1[iter][kter] * matrix2[kter][jter] * (-1));
                } else {
                    outMatrix[iter][jter] = outMatrix[iter][jter] + (matrix1[iter][kter] * matrix2[kter][jter]);
                }
            }
        }
    }
    return outMatrix;
}

void printMatrix(float **inMatrix, int inRows, int inCols, char matrixLabel) {
    printf("\nPrinting Matrix `%c`: ", matrixLabel);
    for (int row=0; row<inRows; row++) {
        printf("\n");
        for (int col=0; col<inCols; col++) {
            printf("%.2f ", inMatrix[row][col]);
        }
    }
}

int main() {
    float **A = (float **)malloc(maxRows * sizeof(float *));
    float **b = (float **)malloc(maxRows * sizeof(float *));
    float **DInverse = (float **)malloc(maxRows * sizeof(float *));
    float **L = (float **)malloc(maxRows * sizeof(float *));
    float **U = (float **)malloc(maxRows * sizeof(float *));
    float **x = (float **)malloc(maxRows * sizeof(float *));
    int iterations;

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    if (A == NULL || b == NULL || DInverse == NULL || L == NULL || U == NULL || x == NULL) {
        printMemoryAllocFailed();
        return (EXIT_FAILURE);
    }

    for (int row = 0; row < maxRows; row++) {
        A[row] = (float *)malloc(maxCols * sizeof(float));
        b[row] = (float *)malloc(sizeof(float));
        x[row] = (float *)calloc(1, sizeof(float));
        DInverse[row] = (float *)malloc(maxCols * sizeof(float));
        L[row] = (float *)malloc(maxCols * sizeof(float));
        U[row] = (float *)malloc(maxCols * sizeof(float));

        if (A[row] == NULL || b[row] == NULL || DInverse[row] == NULL || L[row] == NULL || U[row] == NULL || x[row] == NULL) {
            for (int i = 0; i <= row; i++) {
                free(A[i]);
                free(b[i]);
                free(DInverse[i]);
                free(L[i]);
                free(U[i]);
                free(x[i]);
            }
            free(A);
            free(b);
            free(DInverse);
            free(L);
            free(U);
            free(x);
            printMemoryAllocFailed();
            return (EXIT_FAILURE);
        }
    }

    // FILL: `A`
    printf("Enter the elements of Matrix `A`:\n");
    for (int row = 0; row < maxRows; row++) {
        for (int col = 0; col < maxCols; col++) {
            printf("Row %d, Column %d: ", row + 1, col + 1); scanf("%f", &A[row][col]);
        }
    }

    // FILL: `b`
    printf("Enter the elements of Matrix `b`:\n");
    for (int row = 0; row < maxRows; row++) {
        for(int col = 0; col < 1; col++) {
            printf("Row %d, Column %d: ", row + 1, col + 1); scanf("%f", &b[row][0]);
        }
    }

    // FILL: `DInverse`, `U`, `L`
    for (int row = 0; row < maxRows; row++) {
        for (int col = 0; col < maxCols; col++) {
            float currentValue = A[row][col];
            if (row < col) {
                U[row][col] = currentValue;
            } else if (row > col) {
                L[row][col] = currentValue;
            } else {
                DInverse[row][col] = 1 / currentValue;
            }
        }
    }

    // x^{k} = -D^{-1}*(L+U)*x{k-1} + D^{-1}*b
    // -D^{-1}*(L+U): term1
    // D^{-1}*b: term2
    float **term1 = mul2Matrix(DInverse, maxRows, maxCols, add2Matrix(L, U, maxRows, maxCols), maxRows, maxCols, true);
    float **term2 = mul2Matrix(DInverse, maxRows, maxCols, b, maxRows, 1, false);

    for (int xter = 0; xter < iterations; xter++) {
        printf("\nIteration %d: ", (xter + 1));
        printMatrix(x, maxRows, 1, 'x');
        x = add2Matrix(mul2Matrix(term1, maxRows, maxCols, x, maxRows, 1, false), term2, maxRows, 1);
    }

    // Free remaining matrices
    for (int row = 0; row < maxRows; row++) {
        free(A[row]);
        free(b[row]);
        free(DInverse[row]);
        free(L[row]);
        free(U[row]);
        free(x[row]);
    }

    free(A);
    free(b);
    free(DInverse);
    free(L);
    free(U);
    free(x);
    free(term1);
    free(term2);

    return (EXIT_SUCCESS);
}
