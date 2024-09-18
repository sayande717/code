#include<stdio.h>
#include<omp.h>

int main() {
    int numThreads;
    printf("Enter the number of threads (< %d): ",omp_get_max_threads());
    scanf("%d",&numThreads);
    omp_set_num_threads(numThreads);

    printf("\nThe below text will be printed %d times.",numThreads);
    
    #pragma omp parallel
    printf("\n[%d] The early bird catches the worm.",omp_get_thread_num());

    return 0;
}