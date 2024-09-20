#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<stdbool.h>

int findSum(int *arr, int size, bool parallelize) {
    long sum = 0;
    # pragma omp parallel for reduction(+:sum) if (parallelize)
    for(int index=0;index<size;index++) {
        arr[index] = 999;
        sum = sum + arr[index];
    }
    return sum;
}

int main() {
    int maxRows;
    long sum;
    double start, end, serialExecTime, parallelExecTime;
    printf("Enter number of elements: "); scanf("%d",&maxRows);
    int *arr = (int *)malloc(sizeof(int)*maxRows);

    // Serial 
    start = omp_get_wtime();
    sum = findSum(arr,maxRows,0);
    end = omp_get_wtime();
    serialExecTime = (end-start);
    printf("\nSum: %ld",sum);
    printf("\nSerial Execution Time: %lf",serialExecTime);

    // Parallel
    start = omp_get_wtime();
    sum = findSum(arr,maxRows,1);
    end = omp_get_wtime();
    parallelExecTime = (end-start);
    printf("\nSum: %ld",sum);
    printf("\nParallel Execution Time: %lf",parallelExecTime);

    printf("\nDifference: %lf",(serialExecTime-parallelExecTime));

    printf("\n");
    return EXIT_SUCCESS;
}
