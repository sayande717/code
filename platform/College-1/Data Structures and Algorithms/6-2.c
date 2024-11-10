#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20

void merge(char* arr, int low, int mid, int high) {
    int left = low;
    int right = mid+1;
    char* temp = (char*)malloc(sizeof(char)*(high-low+1));
    int tempIndex = 0;

    while(left<=mid && right<=high) {
        if(arr[left]<=arr[right]) {
            temp[tempIndex] = arr[left];
            left++;
        } else {
            temp[tempIndex] = arr[right];
            right++;
        }
        tempIndex++;
    }

    while(left<=mid) {
        temp[tempIndex] = arr[left];
        left++;
        tempIndex++;
    }

    while(right<=high) {
        temp[tempIndex] = arr[right];
        right++;
        tempIndex++;
    }

    for(int index=low;index<=high;index++) {
        arr[index] = temp[index-low];
    }
    free(temp);
}

void mergeSort(char* arr, int low, int high) {
    // Base case
    if(low==high) {
        return;
    }

    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

void printArr(char* arr, int size) {
    for(int index=0;index<size;index++) {
        printf("%c ",arr[index]);
    }
}   

int main() {
    char* city = (char*)malloc(sizeof(char)*MAX_SIZE);
    printf("Enter city name (atleast 8 characters): "); scanf("%s",city);

    // Find string length (not using strlen())
    int size=0;
    while(city[size]!='\0') {
        size++;
    }

    printf("Original array: "); printArr(city,size);
    mergeSort(city, 0, size-1);
    printf("\nSorted array: "); printArr(city,size);

    printf("\n");
    free(city);
    return EXIT_SUCCESS;
}
