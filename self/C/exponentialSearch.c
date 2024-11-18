#include <stdio.h>
#include <stdbool.h>
#define maxElements 10

void printArr(int *arr) {
    for(int i = 0; i < maxElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr) {
    bool isSwapped = false;
    for(int iter = 0;iter<maxElements-1;iter++) {
        isSwapped = false;
        for(int jter=0;jter<(maxElements-iter-1);jter++) {
            if(arr[jter]>arr[jter+1]) {
                isSwapped = true;
                int temp = arr[jter];
                arr[jter] = arr[jter+1];
                arr[jter+1] = temp;
            }
        }
        if(!isSwapped) {
            return;
        }
    }
}

int binarySearch(int *arr, int target, int low, int high) {
    // Base case
    if(low>high) {
        return -1;
    }
    int mid = low+(high-low)/2;
    if(arr[mid]<target) {
        return binarySearch(arr,target,mid+1,high);
    } else if(arr[mid]>target) {
        return binarySearch(arr,target,low,mid-1);
    } else {
        return mid;
    }
}

int exponentialSearch(int *arr, int target) {
    if(arr[0]==target) {
        return 0;
    }

    int index = 1;
    int low, high;
    while(arr[index]<target && index < maxElements) {
        index *= 2;
    }
    low = index/2;
    high = (index < maxElements)?index:maxElements-1;

    return binarySearch(arr, target, low, high);
}

int main() {
    int arr[maxElements] = {9, 3, 7, 1, 19, 11, 13, 5, 17, 15};
    printf("Original array: "); printArr(arr);
    bubbleSort(arr);
    printf("Modified array: "); printArr(arr);
    int target;

    printf("Enter the target element: "); scanf("%d", &target);
    printf("Target element found at index: %d\n", exponentialSearch(arr, target));

    return 0;
}