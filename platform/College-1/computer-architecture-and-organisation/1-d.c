#include<stdio.h>
#include<omp.h>

int main() {
    #pragma omp parallel
    printf("\nThread ID: %d",omp_get_thread_num());
    return 0;
}