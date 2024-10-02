// INFO: Using students' height as the paramter.
#include <stdio.h>
#include <stdlib.h>

// Iterative Interpolation Search
int interpolationSearch(int* arr, int size, int target) {
    int low = 0;
    int high = size-1;
    int mid = (int) low+(((target-arr[low])*(high-low))/(arr[high]-arr[low]));
    while(low<=high) {
        if(arr[mid]<target) {
            low = mid+1;
        } else if(arr[mid]>target) {
            high = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int size,target;
    printf("Enter number of elements: "); scanf("%d",&size);
    int* heights = (int*)malloc(sizeof(int)*size);
    for(int index=0;index<size;index++) {
        printf("Enter height (in cm): "); scanf("%d",&heights[index]);
    }

    printf("\nEnter target height: "); scanf("%d",&target);
    int targetIndex = interpolationSearch(heights,size,target);
    if(targetIndex!=-1) {
        printf("Position of element: %d",targetIndex);
    } else {
        printf("Element not found.");
    }

    printf("\n");
    return EXIT_SUCCESS;
}
