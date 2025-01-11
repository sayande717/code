#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_HEAD 50
#define MAX_REQUESTS 5

int distance(int pos1, int pos2) {
    return abs(pos1 - pos2);
}

void printSeekTime(int totalDistance) {
    printf("\nSeek Time: %d", totalDistance);
}

void FCFS(int* requests) {
    printf("\n\nAlgorithm: First Come First Serve (FCFS)");
    int currentPos = INIT_HEAD;
    int totalDistance = 0;
    for (int request = 0; request < MAX_REQUESTS; request++) {
        int currentReq = requests[request];
        int currentDistance = distance(currentPos, currentReq);
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, currentReq, currentDistance);
        totalDistance += currentDistance;
        currentPos = currentReq;
    }
    printSeekTime(totalDistance);
}

void SSTF(int* requests) {
    printf("\n\nAlgorithm: Shortest Seek Time First (SSTF)");
    int currentPos = INIT_HEAD;
    int* diff = (int*)malloc(sizeof(int) * MAX_REQUESTS);
    int totalDistance = 0;
    int minDistance = 100;
    int minIndex = MAX_REQUESTS;

    for (int request = 0; request < MAX_REQUESTS; request++) {
        diff[request] = distance(currentPos, requests[request]);
    }

    for (int iter = 0; iter < MAX_REQUESTS; iter++) {
        for (int request = 0; request < MAX_REQUESTS; request++) {
            if ((requests[request] != -1) && (diff[request] < minDistance)) {
                minIndex = request;
                minDistance = diff[request];
            }
        }
        totalDistance += minDistance;
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, requests[minIndex], minDistance);
        currentPos = requests[minIndex];
        requests[minIndex] = -1;
        for (int request = 0; request < MAX_REQUESTS; request++) {
            if (requests[request] != -1) {
                diff[request] = distance(currentPos, requests[request]);
            }
        }
        minDistance = 100;
    }
    printSeekTime(totalDistance);
    free(diff);
}

void SCAN(int* requests, int direction) {
    printf("\n\nAlgorithm: SCAN (Elevator)");
    int currentPos = INIT_HEAD;
    int totalDistance = 0;

    int sortedRequests[MAX_REQUESTS];
    memcpy(sortedRequests, requests, sizeof(int) * MAX_REQUESTS);

    for (int i = 0; i < MAX_REQUESTS - 1; i++) {
        for (int j = 0; j < MAX_REQUESTS - i - 1; j++) {
            if (sortedRequests[j] > sortedRequests[j + 1]) {
                int temp = sortedRequests[j];
                sortedRequests[j] = sortedRequests[j + 1];
                sortedRequests[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < MAX_REQUESTS; i++) {
        if (sortedRequests[i] >= currentPos) {
            for (int j = i; j < MAX_REQUESTS; j++) {
                int currentDistance = distance(currentPos, sortedRequests[j]);
                printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[j], currentDistance);
                totalDistance += currentDistance;
                currentPos = sortedRequests[j];
            }
            break;
        }
    }

    for (int i = MAX_REQUESTS - 1; i >= 0; i--) {
        if (sortedRequests[i] < currentPos) {
            int currentDistance = distance(currentPos, sortedRequests[i]);
            printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[i], currentDistance);
            totalDistance += currentDistance;
            currentPos = sortedRequests[i];
        }
    }

    printSeekTime(totalDistance);
}

void C_SCAN(int* requests) {
    printf("\n\nAlgorithm: C-SCAN (Circular SCAN)");
    int currentPos = INIT_HEAD;
    int totalDistance = 0;

    int sortedRequests[MAX_REQUESTS];
    memcpy(sortedRequests, requests, sizeof(int) * MAX_REQUESTS);

    for (int i = 0; i < MAX_REQUESTS - 1; i++) {
        for (int j = 0; j < MAX_REQUESTS - i - 1; j++) {
            if (sortedRequests[j] > sortedRequests[j + 1]) {
                int temp = sortedRequests[j];
                sortedRequests[j] = sortedRequests[j + 1];
                sortedRequests[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < MAX_REQUESTS; i++) {
        if (sortedRequests[i] >= currentPos) {
            for (int j = i; j < MAX_REQUESTS; j++) {
                int currentDistance = distance(currentPos, sortedRequests[j]);
                printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[j], currentDistance);
                totalDistance += currentDistance;
                currentPos = sortedRequests[j];
            }
            break;
        }
    }

    if (currentPos != sortedRequests[0]) {
        int currentDistance = distance(currentPos, sortedRequests[0]);
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[0], currentDistance);
        totalDistance += currentDistance;
        currentPos = sortedRequests[0];
    }

    for (int i = 1; i < MAX_REQUESTS; i++) {
        int currentDistance = distance(currentPos, sortedRequests[i]);
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[i], currentDistance);
        totalDistance += currentDistance;
        currentPos = sortedRequests[i];
    }

    printSeekTime(totalDistance);
}

void C_LOOK(int* requests) {
    printf("\n\nAlgorithm: C-LOOK");
    int currentPos = INIT_HEAD;
    int totalDistance = 0;

    int sortedRequests[MAX_REQUESTS];
    memcpy(sortedRequests, requests, sizeof(int) * MAX_REQUESTS);

    // Sort the requests
    for (int i = 0; i < MAX_REQUESTS - 1; i++) {
        for (int j = 0; j < MAX_REQUESTS - i - 1; j++) {
            if (sortedRequests[j] > sortedRequests[j + 1]) {
                int temp = sortedRequests[j];
                sortedRequests[j] = sortedRequests[j + 1];
                sortedRequests[j + 1] = temp;
            }
        }
    }

    // Move towards the end of the disk
    for (int i = 0; i < MAX_REQUESTS; i++) {
        if (sortedRequests[i] >= currentPos) {
            for (int j = i; j < MAX_REQUESTS; j++) {
                int currentDistance = distance(currentPos, sortedRequests[j]);
                printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[j], currentDistance);
                totalDistance += currentDistance;
                currentPos = sortedRequests[j];
            }
            break;
        }
    }

    // Move to the start of the remaining requests
    if (currentPos != sortedRequests[0]) {
        int currentDistance = distance(currentPos, sortedRequests[0]);
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[0], currentDistance);
        totalDistance += currentDistance;
        currentPos = sortedRequests[0];
    }

    // Move towards the end of the remaining requests
    for (int i = 1; i < MAX_REQUESTS; i++) {
        int currentDistance = distance(currentPos, sortedRequests[i]);
        printf("\nHead moving from %d to %d, distance covered: %d", currentPos, sortedRequests[i], currentDistance);
        totalDistance += currentDistance;
        currentPos = sortedRequests[i];
    }

    printSeekTime(totalDistance);
}

int main() {
    int requests[MAX_REQUESTS] = {63, 34, 45, 20, 98};
    printf("Maximum number of requests: %d", MAX_REQUESTS);

    int requestsFCFS[MAX_REQUESTS], requestsSSTF[MAX_REQUESTS], requestsSCAN[MAX_REQUESTS], requestsCSCAN[MAX_REQUESTS], requestsCLOOK[MAX_REQUESTS];
    memcpy(requestsFCFS, requests, sizeof(requests));
    memcpy(requestsSSTF, requests, sizeof(requests));
    memcpy(requestsSCAN, requests, sizeof(requests));
    memcpy(requestsCSCAN, requests, sizeof(requests));
    memcpy(requestsCLOOK, requests, sizeof(requests));

    FCFS(requestsFCFS);
    SSTF(requestsSSTF);
    SCAN(requestsSCAN, 1);
    C_SCAN(requestsCSCAN);
    C_LOOK(requestsCLOOK);

    printf("\n");
    return EXIT_SUCCESS;
}