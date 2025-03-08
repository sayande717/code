#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include<omp.h>

void printMemoryAllocFailed() {
    fprintf(stderr, "Memory Allocation failed.");
}

float **add2Matrix(float **matrix1, float **matrix2, int *inRows, int *inCols) {
    float **outMatrix = (float **)malloc(*inRows*sizeof(float *));
    if (outMatrix == NULL) {
        printMemoryAllocFailed();
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < *inRows; row++) {
        outMatrix[row] = (float *)calloc(*inCols, sizeof(float));
        if (outMatrix[row] == NULL) {
            printMemoryAllocFailed();
            for (int i=0; i<row; i++) {
                free(outMatrix[i]);
            }
            free(outMatrix);
            exit(EXIT_FAILURE);
        }
    }

    for (int row=0; row<*inRows; row++) {
        for (int col=0; col<*inCols; col++) {
            outMatrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
    return outMatrix;
}

float **mul2Matrix(float **matrix1, int *inRows1, int *inCols1, float **matrix2, int *inRows2, int *inCols2, bool negative) {	 	  	 	   	      	 	    	   	      	    	 	
    if (*inCols1 != *inRows2) {
        printf("Matrix multiplication not possible.");
        exit(EXIT_FAILURE);
    }

    float **outMatrix = (float **)malloc(*inRows1 * sizeof(float *));
    if (outMatrix == NULL) {
        printMemoryAllocFailed();
        exit(EXIT_FAILURE);
    }

    for (int row=0; row<*inRows1; row++) {
        outMatrix[row] = (float *)calloc(*inCols2, sizeof(float));
        if (outMatrix[row] == NULL) {
            printMemoryAllocFailed();
            for (int i = 0; i < row; i++) {
                free(outMatrix[i]);
            }
            free(outMatrix);
            exit(EXIT_FAILURE);
        }
    }

    for (int iter=0; iter<*inRows1; iter++) {
        for (int jter=0; jter<*inCols2; jter++) {
            for (int kter = 0; kter < *inCols1; kter++) {
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

void getInput(int *inRows, int *inCols, int *inIterations) {
    printf("Enter the number of rows & columns of Matrix `A`: "); scanf("%d",inRows);
    *inCols = *inRows;

    printf("Enter the number of iterations: ");
    scanf("%d", inIterations);
}

void fillMatrix(float **inA, float **inb, float **inU, float **inL, float **inDInverse, int *inRows, int *inCols) {
    srand(time(NULL)); // Seed for random
    // FILL: `A` & `b`
    // printf("Enter the elements of Matrix `A`:\n");
    for (int row = 0; row < *inRows; row++) {
	    inb[row][0] = rand()%1000;
        for (int col = 0; col < *inCols; col++) {
	    inA[row][col] = rand()%1000;
    	    float *currentValue = (float *)malloc(sizeof(float));
	    if(currentValue==NULL) {
		printMemoryAllocFailed();
		exit(EXIT_FAILURE);
	    }
	    *currentValue = inA[row][col];
	    // FILL: `U`, `L` & `DInverse`
	    if (row < col) {
                inU[row][col] = *currentValue;
            } else if (row > col) {
                inL[row][col] = *currentValue;
            } else {
                inDInverse[row][col] = 1 / *currentValue;
            }
	    free(currentValue);
        }
    }
}

void printMatrix(float **inMatrix, int *inRows, int *inCols, char matrixLabel) {	 	  	 	   	      	 	    	   	      	    	 	
    printf("\nPrinting Matrix `%c`: ", matrixLabel);
    for (int row=0; row<*inRows; row++) {
        printf("\n");
        for (int col=0; col<*inCols; col++) {
            printf("%.2f ", inMatrix[row][col]);
        }
    }
}

int main() {
    int *maxRows = (int *)malloc(sizeof(int));
    int *maxCols = (int *)malloc(sizeof(int));
    int *maxThreads = (int *)malloc(3); *maxThreads = omp_get_max_threads();
    int *iterations = (int *)malloc(sizeof(int));
    getInput(maxRows, maxCols, iterations);

    float **A = (float **)malloc(*maxRows * sizeof(float *));
    float **b = (float **)malloc(*maxRows * sizeof(float *));
    float **DInverse = (float **)malloc(*maxRows * sizeof(float *));
    float **L = (float **)malloc(*maxRows * sizeof(float *));
    float **U = (float **)malloc(*maxRows * sizeof(float *));
    float **x = (float **)malloc(*maxRows * sizeof(float *));

    if (A==NULL || b==NULL || DInverse==NULL || L==NULL || U==NULL || x==NULL || maxRows==NULL || maxCols==NULL || iterations==NULL) {
        printMemoryAllocFailed();
        return (EXIT_FAILURE);
    }

    for (int row = 0; row < *maxRows; row++) {
        A[row] = (float *)malloc(*maxCols * sizeof(float));
        b[row] = (float *)malloc(sizeof(float));
        x[row] = (float *)calloc(1, sizeof(float));
        DInverse[row] = (float *)malloc(*maxCols * sizeof(float));
        L[row] = (float *)malloc(*maxCols * sizeof(float));
        U[row] = (float *)malloc(*maxCols * sizeof(float));

        if (A[row] == NULL || b[row] == NULL || DInverse[row] == NULL || L[row] == NULL || U[row] == NULL || x[row] == NULL) {	 	  	 	   	      	 	    	   	      	    	 	
            for (int i = 0; i <= *maxRows; i++) {
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

    fillMatrix(A,b,U,L,DInverse,maxRows,maxCols);
    
    // x^{k} = -D^{-1}*(L+U)*x{k-1} + D^{-1}*b
    // -D^{-1}*(L+U): term1
    // D^{-1}*b: term2

    float **term1 = mul2Matrix(DInverse, maxRows, maxCols, add2Matrix(L, U, maxRows, maxCols), maxRows, maxCols, true);
    float **term2 = mul2Matrix(DInverse, maxRows, maxCols, b, maxRows, &(int){1}, false);

    for(int numThreads=1;numThreads<=*maxThreads;numThreads++) {
        omp_set_num_threads(numThreads);
        double startTime = omp_get_wtime();
        #pragma omp parallel for
        for (int xter = 0; xter < *iterations; xter++) {
            x = add2Matrix(mul2Matrix(term1, maxRows, maxCols, x, maxRows, &(int){1}, false), term2, maxRows, &(int){1});
        }
        double endTime = omp_get_wtime();
        printf("\nExecution time, using %d threads: %lf",numThreads,(endTime-startTime));
    }

    // Free memory
    free(maxRows);
    free(maxCols);
    free(maxThreads);
    free(iterations);

    for (int row = 0; row < *maxRows; row++) {
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
