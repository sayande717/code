#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {
    // Master Thread
    long sumFirst = 0;
    long sumSecond = 0;
    long sumFinal = 0;
    omp_set_num_threads(2);
    # pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        if(threadID==0) {
            # pragma omp parallel for
            for(int iter=1;iter<=50;iter++) {
                sumFirst+=iter;
            }
        } else {
            # pragma omp parallel for
            for(int iter=51;iter<=100;iter++) {
                sumSecond+=iter;
            }
        }
    }
    // Master Thread
    # pragma omp barrier
    sumFinal = sumFirst+sumSecond;
    printf("\nSum: %ld",sumFinal);

    printf("\n");
    return EXIT_SUCCESS;
}
