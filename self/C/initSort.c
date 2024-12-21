#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxArrSize 10

/* Index:
 * Merge Sort
 * Insertion Sort
 * Bubble Sort
 * Cocktail Sort
*/

void merge(int *arr, int low, int mid, int high) {
    int left = low;
    int right = mid+1;
    // 4. Intermediate temporary array stores the sorted and merged array.
    int *tempArr = (int*)malloc(sizeof(int)*(high-low+1));
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

void mergeSort(int* arr, int low, int high) {
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
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int* arr) {
    // arr[0] is assumed to be sorted.
    for(int iter=1;iter<maxArrSize;iter++) {
        int target = arr[iter];
        int jter = iter-1;
        // Here, we compare the target with array elements [1 to (i-1)], and put the key in it's proper position.
        // DECREASING: arr[jter<target]
        while(jter>=0 && arr[jter]>target) {
            // The target gets overwritten in the array.
            arr[jter+1] = arr[jter];
            jter = jter - 1;
        }
        // Restore the target.
        // WARN: j is either -1, or 1 index before the target here.
        arr[jter+1] = target;
    }
}

void bubbleSort(int* arr) {
    // Outer loop gives the limit till which the array is traversed.
    // The limit starts at (arr.length-1), and ends at 1.
    for(int iter=maxArrSize-1;iter>0;iter--) {
        bool isSwapped = false;
        // The array is traversed in this loop.
        // Pass 1: We traverse from 0 to (arr.length-2). In the end, the last element is sorted.
        // Pass 2: We traverse from 0 to (arr.length-3). In the end, the last 2 elements are sorted.
        // Pass 3: We traverse from 0 to (arr.length-4). In the end, the last 3 elements are sorted.

        for(int jter=0;jter<iter;jter++) {
            if(arr[jter]>arr[jter+1]) {
                isSwapped = true;
                int temp = arr[jter];
                arr[jter] = arr[jter+1];
                arr[jter+1] = temp;
            }
        }

        // If no swap occurs in the current pass, it means the array is sorted.
        if(!isSwapped) {
            break;
        }
    }
}

void cocktailSort(int* arr) {
    int start = 0;
    int end = maxArrSize-1;
    bool isSwapped = false;

    // Condition 1: Checks if the limits are logical.
    // Condition 2: Checks if any swap has taken place in the previous pass.
    while(start<end || !isSwapped) {
        isSwapped = false;
        for(int forwardIter=start;forwardIter<end;forwardIter++) {
            if(arr[forwardIter]>arr[forwardIter+1]) {
                isSwapped = true;
                int temp = arr[forwardIter];
                arr[forwardIter] = arr[forwardIter+1];
                arr[forwardIter+1] = temp;
            }
        }

        // Element at arr[end] is at it's proper spot.
        // In Pass 1, the largest element is at the last index.
        end--;

        for(int backwardIter=end-1;backwardIter>=start;backwardIter--) {
            if(arr[backwardIter]>arr[backwardIter+1]) {
                isSwapped = true;
                int temp = arr[backwardIter];
                arr[backwardIter] = arr[backwardIter+1];
                arr[backwardIter+1] = temp;
            }
        }

        // Element at arr[start] is at it's proper spot.
        // In Pass 1, the smallest element is at the first index.
        start++;
    }
}

int main() {
    int *arr = (int *)malloc(sizeof(int)*maxArrSize);
    int initialArr[] = {9,8,7,6,5,4,3,2,2,1};
    for (int index = 0; index < maxArrSize; index++) {
        arr[index] = initialArr[index];
    }

    printf("Original Array: "); printArr(arr, maxArrSize);
    
    // Runner
    // mergeSort(arr, 0, maxArrSize-1);
    insertionSort(arr);
    // bubbleSort(arr);
    //cocktailSort(arr);

    printf("Sorted Array: "); printArr(arr, maxArrSize);

    return EXIT_SUCCESS;
}
