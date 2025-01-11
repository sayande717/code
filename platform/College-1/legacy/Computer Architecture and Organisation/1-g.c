#include<stdio.h>
#include<stdbool.h>
#include<omp.h>

// Translates boolean from 1/0 to true/false.
char* translateBoolean(bool input) {
    return input?"true":"false";
}

int main() {
    printf("\nParallel? %s",translateBoolean(omp_in_parallel()));

    #pragma omp parallel
    printf("\nParallel? %s",translateBoolean(omp_in_parallel()));
}