#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fillArr(int *arr, int size) {
    # pragma omp parallel for
    for(int index=0;index<size;index++) {
        arr[index] = rand()*1000;
    }
}

int main() {
    int index,size;
    long sum= 0;
    printf("Enter the number of elements: "); scanf("%d",&size);
    int *arr = (int *)malloc(sizeof(int)*size);
    if(arr==NULL) {
        printf("Memory allocation failed.");
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    fillArr(arr,size);

    double start = omp_get_wtime();
    // shared: arr, the array itself.
    // private: index, to prevent data race when incrementing it's value.
    // firstprivate: sum & size, so we can get their initial values.
    // lastprivate: sum, so we can get the final sum of all elements.
    # pragma omp parallel for shared(arr) private(index) firstprivate(sum,size) lastprivate(sum)
    for(index=0;index<size;index++) {
        sum = sum + arr[index];
    }
    double end = omp_get_wtime();
    
    printf("\nExecution Time: %lf",(end-start));
    printf("\nSum: %ld",sum);
    printf("\nFinal value of index: %d",index);


    free(arr);
    printf("\n");
    return EXIT_SUCCESS;
}
