#include<stdio.h>
#include<stdlib.h>
#define maxArrSize 10

void merge(int *arr, int low, int mid, int high) {
    int left = low;
    int right = mid+1;
    // 4. Intermediate temporary array stores the sorted and merged array.
    int *tempArr = (int *)malloc(sizeof(int)*(high-low+1));
    int tempArrIter = 0; // iterator for tempArr: 0 to (high-low+1), the latter being the total length of both (hypothetical) sub-arrays.
    while(left<=mid && right<=high) {
        // 4. START merging the (hypothetical) arrays
        if(arr[left]<=arr[right]) {
            tempArr[tempArrIter] = arr[left];
            left++;
        } else {
            tempArr[tempArrIter] = arr[right];
            right++;
        }
        tempArrIter++;
    }

    //  Put any remaining elements of left (hypothetical) sub-array into the temp[] array
    while(left<=mid) {
        tempArr[tempArrIter] = arr[left];
        left++;
        tempArrIter++;
    }

    // Put any remaining elements of right (hypothetical) sub-array into the temp[] array
    while(right<=high) {
        tempArr[tempArrIter] = arr[right];
        right++;
        tempArrIter++;
    }

    // Put the temporary sorted array elements in the original one
    for(int index=low;index<=high;index++) {
        arr[index] = tempArr[index-low]; // if low & high = 5 & 8, index-low will be 5-5=0, 6-5=1,7-5=2 ... which is the index we need for tempArr.
    }
}

void mergeSort(int *arr, int low, int high) {
    // Base case: Array only has 1 element, so low and high points to the same variable.
    // (arr,1,1) represents such an array.
    if(low==high) {
        return;
    }

    int mid = low+(high-low)/2;
    // DIVIDE
    mergeSort(arr,low,mid); // 1. Sort the 1st half of the array.
    mergeSort(arr,mid+1,high); // 2. Sort the 2nd half of the array.
    
    // CONQUER (Sort) & MERGE
    merge(arr,low,mid,high); // 3. Sort & Merge the array.
}

void printArr(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = (int *)malloc(sizeof(int)*maxArrSize);
    int initialArr[] = {9,4,2,7,5,1,8,3,6,0};
    for (int i = 0; i < maxArrSize; i++) {
        arr[i] = initialArr[i];
    }

    printArr(arr, maxArrSize);
    mergeSort(arr, 0, maxArrSize-1);
    printArr(arr, maxArrSize);

    return EXIT_SUCCESS;
}