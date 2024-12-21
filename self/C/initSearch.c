#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 10
/* Index:
 * Linear Search
 * Binary Search
 * Interpolation Search
 * Exponential Search
*/

void print_arr(int* arr) {
    printf("Elements: ");
    for(int index=0;index<MAX_LEN;index++) {
        printf("%n ",arr[index]);
    }
    printf("\n");
}

int linear_search(int* arr, int target) {
    for(int index=0;index<MAX_LEN;index++) {
        if(arr[index]==target) {
            return index;
        }
    }
    return -1;
}

int binary_search_iterative(int* arr, int target) {
    int start=0;
    int end=MAX_LEN-1;
    while(start<=end) {
        int mid = start+(end-start)/2;
        if(arr[mid]<target) {
            start = mid+1;
        } else if(arr[mid]>target) {
            end = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binary_search_recursive(int* arr, int target, int start, int end) {
    if(start>end) {
        return -1;
    }

    int mid = start+(end-start)/2;
    if(arr[mid]<target) {
        binary_search_recursive(arr,target,mid+1,end);
    } else if(arr[mid]>target) {
        binary_search_recursive(arr,target,start,mid-1);
    }
}

int main() {
    srand(time(NULL));
    int *arr = (int*)malloc(sizeof(int));
    if(arr==NULL) {
        printf("Memory allocation failed.");
        return EXIT_FAILURE;
    }
    for(int index=0;index<MAX_LEN;index++) {
        arr[index]=rand()%11;
    }
    print_arr(arr);
    
    free(arr);
    return EXIT_SUCCESS;
}