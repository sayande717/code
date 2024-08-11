#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<stdbool.h>

void input(int *rows, int *cols) {
    printf("Enter the number of rows: "); scanf("%d",&*rows);
    printf("Enter the number of columns: "); scanf("%d",&*cols);
}

int **initArr(int rows, int cols) {
    int **newArr = (int **)malloc(rows*sizeof(int *));
    for(int iter=0;iter<rows;iter++) {
        newArr[iter]=(int *)malloc(cols*sizeof(int));
        if(newArr[iter]==NULL) {
            fprintf(stderr,"Memory allocation failed.");
            exit(1);
        }
    }
    return newArr;
}

//  For freeing memory, we need the array itself, and free all arrays created accross it's rows.
void freeArrMEM(int **inArr, int rows) {
    for(int iter=0;iter<rows;iter++) {
        free(inArr[iter]);
    }
    free(inArr);
}

void fillArr(int **inArr, int rows, int cols) {
    for(int iter=0; iter<rows; iter++) {
        for(int jter=0; jter<cols; jter++) {
            inArr[iter][jter] = rand() % (10000);
        }
    }
}

int **transposeArr(int **inArr, int **outArr, int outRows, int outCols, bool parallel) {
    // if(parallel==1) then parallelize the for loop

    #pragma omp parallel for if(parallel)
    for(int iter=0;iter<outRows;iter++) {
        for(int jter=(iter+1);jter<outCols;jter++) {
            int temp = outArr[iter][jter];
            outArr[iter][jter] = outArr[jter][iter];
            outArr[jter][iter] = temp;
        }
    }
    return outArr;
}

int main() {

    int inRows, inCols;
    int outRows, outCols;
    // Take the number of rows and columns of input array
    input(&inRows,&inCols);
    int **inArr = initArr(inRows,inCols);

    int **outArr;
    if(inRows!=inCols) {
        outRows = inCols;
        outCols = inRows;
    } else {
        outRows = inCols;
        outCols = inRows;
    }
    outArr = initArr(outRows,outCols);

    fillArr(inArr,inRows,inCols);

    double start, end;
    start = omp_get_wtime();
    outArr = transposeArr(inArr,outArr,outRows,outCols,0); // 0: Serial
    end = omp_get_wtime();
    printf("\nSerial Execution time: %f", (end-start));

    start = omp_get_wtime();
    outArr = transposeArr(inArr,outArr,outRows,outCols,1); // 1: Parallel
    end = omp_get_wtime();
    printf("\nParallel Execution time: %f", (end-start));

    printf("\n");

    freeArrMEM(inArr,inRows);
    freeArrMEM(outArr,outRows);
}
