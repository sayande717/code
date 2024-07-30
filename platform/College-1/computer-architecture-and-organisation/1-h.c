#include<stdio.h>
#include<omp.h>

int main() {
    
    #pragma omp parallel for 
    for(int iter=0;iter<4;iter++) {
        printf("\nIteration: %d",iter);
    }

    printf("\n");

    #pragma omp parallel for
    for(int iter=0;iter<4;iter++) {
        printf("\nIteration: %d",iter);
    }
}