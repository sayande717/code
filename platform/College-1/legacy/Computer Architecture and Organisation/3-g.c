#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void addMatrix(int** matrix1, int** matrix2, int** matrixResult, int rows, int cols, char* scheduleType, int chunkSize) {
    bool runParallel = true;
    if(strcmp(scheduleType,"serial")==0) {
        runParallel = false;
    } else if(strcmp(scheduleType,"static")==0) {
        omp_set_schedule(omp_sched_static,chunkSize);
    } else if(strcmp(scheduleType,"dynamic")==0) {
        omp_set_schedule(omp_sched_dynamic,chunkSize);
    } else if(strcmp(scheduleType,"guided")==0) {
        omp_set_schedule(omp_sched_guided,chunkSize);
    } else if(strcmp(scheduleType,"auto")==0) {
        omp_set_schedule(omp_sched_auto,chunkSize);
    } else {
        fprintf(stderr,"Wrong scheduling clause");
        exit(EXIT_FAILURE);
    }

    # pragma omp parallel for schedule(runtime) if(runParallel)
    for(int row=0;row<rows;row++) {
        for(int col=0;col<cols;col++) {
            matrixResult[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

void printOutput(char* schedulingClause, double executionTime) {
    printf("\nScheduling Clause: %s\n",schedulingClause);
    printf("Execution Time: %lf",executionTime);
}

void readMatrix(char* filename, int** matrix, int rows, int cols) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            fscanf(file, "%d", &matrix[row][col]);
        }
    }

    fclose(file);
}

void writeMatrix(char* filename, int** matrix, int rows, int cols) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            fprintf(file, "%d ", matrix[row][col]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    int rows,cols,chunkSize;
    // Matrix-1 & Matrix-2 are already defined as a static file.
    rows = 5000; cols = 5000;
    printf("Enter the chunk size: "); scanf("%d",&chunkSize);

    int** matrix1   = (int**)malloc(sizeof(int*)*cols);
    int** matrix2   = (int**)malloc(sizeof(int*)*cols);
    int** matrixSum = (int**)malloc(sizeof(int*)*cols);
    if(matrix1==NULL || matrix2==NULL || matrixSum==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return EXIT_FAILURE;
    }
    for(int col=0;col<cols;col++) {
        matrix1[col] = (int*)malloc(sizeof(int)*rows);
        matrix2[col] = (int*)malloc(sizeof(int)*rows);
        matrixSum[col] = (int*)malloc(sizeof(int)*rows);
        if(matrix1[col]==NULL || matrix2[col]==NULL || matrixSum[col]==NULL) {
            fprintf(stderr,"Memory allocation failed.");
            return EXIT_FAILURE;
        }
    }

    // Read matrices from files
    readMatrix("3-g-initMatrix1.txt", matrix1, rows, cols);
    readMatrix("3-g-initMatrix2.txt", matrix2, rows, cols);

    double start,end;
    char* schedulingClause = (char*)malloc(sizeof(char)*8);
    if(schedulingClause==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return EXIT_FAILURE;
    }
    
    // Execution: serial
    strcpy(schedulingClause,"serial\0");
    start = omp_get_wtime();
    addMatrix(matrix1,matrix2,matrixSum,rows,cols,schedulingClause,chunkSize);
    writeMatrix("3-g-finalMatrixSerial.txt", matrixSum, rows, cols);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / static
    strcpy(schedulingClause,"static\0");
    start = omp_get_wtime();
    addMatrix(matrix1,matrix2,matrixSum,rows,cols,schedulingClause,chunkSize);
    writeMatrix("3-g-finalMatrixParallelStatic.txt", matrixSum, rows, cols);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / dynamic 
    strcpy(schedulingClause,"dynamic\0");
    start = omp_get_wtime();
    addMatrix(matrix1,matrix2,matrixSum,rows,cols,schedulingClause,chunkSize);
    writeMatrix("3-g-finalMatrixParallelDynamic.txt", matrixSum, rows, cols);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / auto  
    strcpy(schedulingClause,"auto\0");
    start = omp_get_wtime();
    addMatrix(matrix1,matrix2,matrixSum,rows,cols,schedulingClause,chunkSize);
    writeMatrix("3-g-finalMatrixParallelAuto.txt", matrixSum, rows, cols);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));
    
    // Free Memory
    free(schedulingClause);
    for(int col=0;col<cols;col++) {
        free(matrix1[col]);
        free(matrix2[col]);
        free(matrixSum[col]);
    }
    free(matrix1);
    free(matrix2);
    free(matrixSum);

    printf("\n");
    return 0;
}

