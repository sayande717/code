#include<stdio.h>
#include<omp.h>

int main() {
    printf("Number of processor cores: %d",omp_get_num_procs());
    return 0;
}