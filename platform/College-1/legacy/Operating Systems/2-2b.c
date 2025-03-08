#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxProcesses 5  // Max Processes
#define maxResources 3  // Max Resources

int *available;
int **max;
int **allocation;
int **need;

void calculateNeed() {
    for (int iter = 0; iter < maxProcesses; iter++) {
        for (int jter = 0; jter < maxResources; jter++) {
            need[iter][jter] = max[iter][jter] - allocation[iter][jter];
        }
    }
}

bool isSafe() {
    int *work = (int*)malloc(sizeof(int) * maxResources);
    bool *finish = (bool*)malloc(sizeof(bool) * maxProcesses);
    for (int iter = 0; iter < maxResources; iter++) {
        work[iter] = available[iter];
    }
    for (int iter = 0; iter < maxProcesses; iter++) {
        finish[iter] = false;
    }

    for (int iter = 0; iter < maxProcesses; iter++) {
        for (int jter = 0; jter < maxProcesses; jter++) {
            if (!finish[jter]) {
                bool canAllocate = true;
                for (int kter = 0; kter < maxResources; kter++) {
                    if (need[jter][kter] > work[kter]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int kter = 0; kter < maxResources; kter++) {
                        work[kter] += allocation[jter][kter];
                    }
                    finish[jter] = true;
                    iter = -1;  // Restart the loop
                }
            }
        }
    }

    for (int iter = 0; iter < maxProcesses; iter++) {
        if (!finish[iter]) {
            free(work);
            free(finish);
            return false;
        }
    }

    free(work);
    free(finish);
    return true;
}

bool requestResources(int process, int request[]) {
    for (int iter = 0; iter < maxResources; iter++) {
        if (request[iter] > need[process][iter]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return false;
        }
    }

    for (int iter = 0; iter < maxResources; iter++) {
        if (request[iter] > available[iter]) {
            printf("Resources are not available.\n");
            return false;
        }
    }

    for (int iter = 0; iter < maxResources; iter++) {
        available[iter] -= request[iter];
        allocation[process][iter] += request[iter];
        need[process][iter] -= request[iter];
    }

    if (isSafe()) {
        printf("\nResources allocated successfully.\n");
        return true;
    } else {
        for (int iter = 0; iter < maxResources; iter++) {
            available[iter] += request[iter];
            allocation[process][iter] -= request[iter];
            need[process][iter] += request[iter];
        }
        printf("\nResources allocation failed. System is not in a safe state.\n");
        return false;
    }
}

void printMatrix(int matrix[maxProcesses][maxResources]) {
    printf("\n");
    for(int row=0;row<maxProcesses;row++) {
	    for(int col=0;col<maxResources;col++) {
	        printf("%d ",matrix[row][col]);
    	}
	printf("\n");
    }
}

int main() {
    available = (int*)malloc(sizeof(int)*maxResources);
    max = (int**)malloc(sizeof(int*)*maxProcesses);
    allocation = (int**)malloc(sizeof(int*)*maxProcesses);
    need = (int**)malloc(sizeof(int*)*maxProcesses);

    for (int iter = 0; iter < maxProcesses; iter++) {
        max[iter] = (int*)malloc(maxResources * sizeof(int));
        allocation[iter] = (int*)malloc(maxResources * sizeof(int));
        need[iter] = (int*)malloc(maxResources * sizeof(int));
    }

    available[0] = 3;
    available[1] = 3;
    available[2] = 2;

    int maxMatrix[maxProcesses][maxResources] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    printf("Maximum Matrix: ");
    printMatrix(maxMatrix);

    int allocationMatrix[maxProcesses][maxResources] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    printf("Allocation Matrix: ");
    printMatrix(maxMatrix);

    for (int iter = 0; iter < maxProcesses; iter++) {
        for (int jter = 0; jter < maxResources; jter++) {
            max[iter][jter] = maxMatrix[iter][jter];
            allocation[iter][jter] = allocationMatrix[iter][jter];
        }
    }

    calculateNeed();

    int request[maxResources] = {1, 0, 2};
    printf("\nResources: ");
    for(int index=0;index<maxResources;index++) {
	printf("%d ",request[index]);
    }

    int process = 1;

    if (requestResources(process, request)) {
        printf("Request granted.\n");
    } else {
        printf("Request denied.\n");
    }

    // FREE Memory
    free(available);
    for (int iter = 0; iter < maxProcesses; iter++) {
        free(max[iter]);
        free(allocation[iter]);
        free(need[iter]);
    }
    free(max);
    free(allocation);
    free(need);

    return 0;
}

