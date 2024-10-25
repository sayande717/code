#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<stdbool.h>

void input(int arrID, int *rows, int *cols) {
    printf("Enter the number of rows of Matrix %d: ",(arrID+1)); scanf("%d",&*rows);
    printf("Enter the number of columns of Matrix %d: ",(arrID+1)); scanf("%d",&*cols);
}

bool checkSize(int rows0, int cols0, int rows1, int cols1) {
    if(rows0==rows1 && cols0==cols1) {
        return 1;
    }
    return 0;
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

int **addArr(int **inArr0, int **inArr1, int **outArr, int outRows, int outCols, bool parallel) {
    // if(parallel==1) then parallelize the for loop
    #pragma omp parallel for if(parallel)
    for(int iter=0;iter<outRows;iter++) {
        for(int jter=0;jter<outCols;jter++) {
            outArr[iter][jter] = inArr0[iter][jter]+inArr1[iter][jter];
        }
    }
    return outArr;
}

int main() {

    int inRows0, inCols0;
    int inRows1, inCols1;
    int outRows, outCols;
    // Take the number of rows and columns of input array
    input(0,&inRows0,&inCols0);
    input(1,&inRows1,&inCols1);
    if(checkSize(inRows0,inCols0,inRows1,inCols1)==0) {
        // print to stderr instead of stdout
        fprintf(stderr,"Number of rows & columns must be same for both matrices.");
        return 0;
    }

    int **inArr0 = initArr(inRows0,inCols0);
    int **inArr1 = initArr(inRows1,inCols1);
    int **outArr = initArr(outRows,outCols);

    fillArr(inArr0,inRows0,inCols0);
    fillArr(inArr1,inRows1,inCols1);

    double start, end;
    start = omp_get_wtime();
    outArr = addArr(inArr0,inArr1,outArr,outRows,outCols,0); // 0: Serial
    end = omp_get_wtime();
    printf("\nSerial Execution time: %f", (end-start));

    start = omp_get_wtime();
    outArr = addArr(inArr0,inArr1,outArr,outRows,outCols,1); // 1: Parallel
    end = omp_get_wtime();
    printf("\nParallel Execution time: %f", (end-start));

    printf("\n");

    freeArrMEM(inArr0,inRows0);
    freeArrMEM(inArr1,inRows1);
    freeArrMEM(outArr,outRows);
}
