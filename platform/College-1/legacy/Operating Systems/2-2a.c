#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define P 5  // Number of processes
#define R 3  // Number of resources

int available[R] = {3, 3, 2};  // Available instances of resources
int max[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};  // Maximum demand of each process
int allocation[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};  // Currently allocated resources
int need[P][R];  // Remaining needs of each process

void calculateNeed() {
    for (int iter = 0; iter < P; iter++) {
        for (int jter = 0; jter < R; jter++) {
            need[iter][jter] = max[iter][jter] - allocation[iter][jter];
        }
    }
}

bool isSafeSequence(int sequence[]) {
    int work[R];
    bool finish[P] = {false};

    for (int jter = 0; jter < R; jter++) {
        work[jter] = available[jter];
    }

    for (int iter = 0; iter < P; iter++) {
        int process = sequence[iter];
        if (!finish[process]) {
            bool canAllocate = true;
            for (int jter = 0; jter < R; jter++) {
                if (need[process][jter] > work[jter]) {
                    canAllocate = false;
                    break;
                }
            }
            if (canAllocate) {
                for (int jter = 0; jter < R; jter++) {
                    work[jter] += allocation[process][jter];
                }
                finish[process] = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

void printSequence(int* sequence) {
    printf(" { ");
    for(int index=0;index<P;index++) {
	printf("%d ",sequence[index]);
    }
    printf("} ");
}

void printSafety(int* sequence) {
    if(isSafeSequence(sequence)) {
        printf("The sequence");
	printSequence(sequence);
	printf("is a safe sequence.\n");
    } else {
        printf("The sequence");
	printSequence(sequence);
	printf("is not a safe sequence.\n");
    }
}

int main() {
    calculateNeed();

    int *safeSequence = (int*)malloc(sizeof(int)*P);
    safeSequence[0] = 1;
    safeSequence[1] = 3;
    safeSequence[2] = 4;
    safeSequence[3] = 0;
    safeSequence[4] = 2;
    
    int *unSafeSequence = (int*)malloc(sizeof(int)*P);
    unSafeSequence[0] = 0;
    unSafeSequence[1] = 1;
    unSafeSequence[2] = 2;
    unSafeSequence[3] = 3;
    unSafeSequence[4] = 4;

    printSafety(safeSequence);
    printSafety(unSafeSequence);

    free(safeSequence);
    free(unSafeSequence);
    return EXIT_SUCCESS;
}

