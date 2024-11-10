#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxArrLen 10

// Bubble sort
void sort(int *arr) {
    for(int iter=0;iter<maxArrLen;iter++) {
        bool isSwapped = 0;
        for(int jter=0;jter<(maxArrLen-iter-1);jter++) {
            if(arr[jter]>arr[jter+1]) {
                isSwapped=1;
                int temp =arr[jter];
                arr[jter]=arr[jter+1];
                arr[jter+1]=temp;
            }
        }
        if(!isSwapped) {
            break;
        }
    }
}

// Iterative
int binarySearch(int *arr, int low, int high, int target) {
    while(low<=high) {
        int mid = low+(high-low)/2;
        if(arr[mid]<target) {
            low = mid+1;
        } else if(arr[mid]>target) {
            high = mid-1;
        } else {
            return mid;
        }
    }
    // EDGE Case: low>high
    return -1;
}

// Iterative
int exponentialSearch(int *arr, int target) {
    // EDGE case: 1st element is the target
    if(arr[0] == target) {
        return 0;
    }
    int index = 1;
    while(arr[index]<target && index<maxArrLen) {
        index = index*2;
    }
    int low = index/2;
    int high = (arr[index]>=target)?(index):(maxArrLen-1);
    return binarySearch(arr,low,high, target);
}


// Recursive
int interpolationSearch(int *arr, int low, int high, int target) {

    // Base Case
    if(low>high) {
        return -1;
    }
    
    int mid = low+((target-arr[low])*(high-low))/(arr[high]-arr[low]);
    if(arr[mid]<target) {
        interpolationSearch(arr,mid+1,high,target);
    } else if(arr[mid]>target) {
        interpolationSearch(arr,low,mid-1,target);
    } else {
        return mid;
    }
}

int main() {
    int *arr = (int *)malloc(sizeof(int)*maxArrLen);
    int target;
    if(arr==NULL) {
        fprintf(stderr,"Memory allocation failed");
        return EXIT_FAILURE;
    }
    
    printf("Number of elements: %d\n",maxArrLen);
    
    for(int index=0;index<maxArrLen;index++) {
        printf("Enter element %d: ",(index+1)); scanf("%d",&arr[index]);
    }
    
    printf("\nEnter Target: "); scanf("%d",&target);
    
    printf("\nOriginal Array: ");
    for(int index=0;index<maxArrLen;index++){
        printf("%d ",arr[index]);
    }
    sort(arr);
    printf("\nSorted Array: ");
    for(int index=0;index<maxArrLen;index++){
        printf("%d ",arr[index]);
    }
    
    printf("\n\nIndex (Position-1): ");
    printf("\nUsing Interpolation Search: %d",interpolationSearch(arr, 0,maxArrLen-1,target));
    printf("\nUsing Exponential Search: %d",exponentialSearch(arr, target));
    
    printf("\n");
    return EXIT_SUCCESS;
}
