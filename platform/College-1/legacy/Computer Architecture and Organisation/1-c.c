#include<stdio.h>
#include<omp.h>

int main() {
    printf("Maximum number of threads: %d\n", omp_get_max_threads());

    return 0;
}
