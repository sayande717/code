#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure definition of a job.
typedef struct Job {
	int JID;
	int deadline;
	int profit;
} jobList;

int compareJobs(const void* a, const void* b) {
	jobList* temp1 = (jobList*)a;
	jobList* temp2 = (jobList*)b;
	return (temp2->profit - temp1->profit);
}

int findMinimum(int num1, int num2) {
	return (num1 > num2) ? num2 : num1;
}

bool printJobScheduling(jobList inArr[], int numberOfJobs) {
	// Sort the jobs
	qsort(inArr, numberOfJobs, sizeof(jobList), compareJobs);

	int result[numberOfJobs];
	bool slot[numberOfJobs];

	for (int iter = 0; iter < numberOfJobs; iter++) {
        slot[iter] = false;
    }
	
	for (int iter0 = 0; iter0 < numberOfJobs; iter0++) {
		for (int iter1 = findMinimum(numberOfJobs, inArr[iter0].deadline) - 1; iter1 >= 0; iter1--) {
			if (slot[iter1] == false) {
				result[iter1] = iter0;
				slot[iter1] = true;
				break;
			}
		}
	}

    bool slotAvailable = 0;
	for (int iter = 0; iter < numberOfJobs; iter++) {
        if (slot[iter]) {
            slotAvailable = 1;
            printf("%d ", inArr[result[iter]].JID);
        }
    }

    if(!slotAvailable) {
        return false;
    }

    return true;
}

int main() {
    // Static Input: Job list
	jobList inArr[] = {
        { 1, 2, 20 },
        { 2, 2, 70 },
        { 3, 1, 40 },
        { 4, 4, 110 },
        { 5, 5, 80 } 
        };

    // If sequence cannot be generated, print a readable error.
	int numberOfJobs = sizeof(inArr) / sizeof(inArr[0]);
	printf("Sequence: ");
    if(!printJobScheduling(inArr, numberOfJobs)) {
        printf("Sequence cannot be generated.");
    }
	return 0;
}
