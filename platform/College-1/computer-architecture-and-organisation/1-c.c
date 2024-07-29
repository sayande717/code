#include<stdio.h>
#include<omp.h>

int main() {
    printf("\nMaximum number of threads: %d", omp_get_max_threads());

    return 0;
}