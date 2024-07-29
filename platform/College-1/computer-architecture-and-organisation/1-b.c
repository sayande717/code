#include<stdio.h>
#include<omp.h>

int main() {
    printf("\nNumber of threads running: %d", omp_get_num_threads());

    # pragma omp parallel
    printf("\nNumber of threads running: %d", omp_get_num_threads());
    
    return 0;
}