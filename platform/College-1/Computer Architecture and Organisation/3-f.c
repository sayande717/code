#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void transposeArr(int **arr,int rows, int cols, char *scheduleType, int chunkSize) {
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
        for(int col=(row+1);col<cols;col++) {
            int temp = arr[row][col];
            arr[row][col] = arr[col][row];
            arr[col][row] = temp;
        }
    }
}

void printOutput(char *schedulingClause, double executionTime) {
    printf("\nScheduling Clause: %s\n",schedulingClause);
    printf("Execution Time: %lf",executionTime);
}

int main() {
    int rows,cols,chunkSize;
    printf("Enter the number of rows: "); scanf("%d",&rows);
    printf("Enter the number of columns: "); scanf("%d",&cols);
    printf("Enter the chunk size: "); scanf("%d",&chunkSize);
    
    int **arr = (int **)malloc(sizeof(int *)*cols);
    if(arr==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return EXIT_FAILURE;
    }
    for(int col=0;col<cols;col++) {
        arr[col] = (int *)calloc(rows,sizeof(int));
        if(arr[col]==NULL) {
            fprintf(stderr,"Memory allocation failed.");
            return EXIT_FAILURE;
        }
    }
    double start,end;
    char *schedulingClause = (char *)malloc(sizeof(char)*8);
    if(schedulingClause==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return EXIT_FAILURE;
    }

    // Execution: serial
    strcpy(schedulingClause,"serial\0");
    start = omp_get_wtime();
    transposeArr(arr,rows,cols,schedulingClause,chunkSize);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / static
    strcpy(schedulingClause,"static\0");
    start = omp_get_wtime();
    transposeArr(arr,rows,cols,schedulingClause,chunkSize);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / dynamic 
    strcpy(schedulingClause,"dynamic\0");
    start = omp_get_wtime();
    transposeArr(arr,rows,cols,schedulingClause,chunkSize);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));

    // Execution: parallel / auto  
    strcpy(schedulingClause,"auto\0");
    start = omp_get_wtime();
    transposeArr(arr,rows,cols,schedulingClause,chunkSize);
    end = omp_get_wtime();
    printOutput(schedulingClause,(end-start));


    // Free Memory
    free(schedulingClause);
    for(int col=0;col<cols;col++) {
        free(arr[cols]);
    }
    free(arr);

    printf("\n");
    return EXIT_SUCCESS;
}
