#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

int findSum(int* arr) {
    omp_set_schedule(omp_sched_static,1);
    int sum = 2;
    # pragma omp parallel for schedule(runtime)
    for(int index=0;index<10;index++) {
        sum += 2;
    }
    return sum;
}

int main() {
    int* arr = (int*)calloc(10,sizeof(int));
    printf("Sum: %d",findSum(arr));
    return EXIT_SUCCESS;
}
