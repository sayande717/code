#include <stdio.h>

void printSlidingWindow(int arr[], int n, int windowSize) {
    for (int i = 0; i <= n - windowSize; i++) {
        printf("Window %d: ", i + 1);
        for (int j = 0; j < windowSize; j++) {
            printf("%d ", arr[i + j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int windowSize = 3;

    printSlidingWindow(arr, n, windowSize);

    return 0;
}