#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
    long sumFirst = 0;
    long sumSecond = 0;
    long sumFinal = 0;
    omp_set_num_threads(2);
    # pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        if(threadID==0) {
            for(int iter=1;iter<=50;iter++) {
                sumFirst+=iter;
            }
        } else {
            for(int iter=51;iter<=100;iter++) {
                sumSecond+=iter;
            }
        }
    }
    sumFinal = sumFirst+sumSecond;
    printf("\nSum: %ld",sumFinal);

    return EXIT_SUCCESS;
}
