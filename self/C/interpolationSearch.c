#include <stdio.h>
#define maxLength 10

int interpolationSearch(int *arr, int target) {
    int low = 0;
    int high = maxLength-1;
    // Assume arr=[1,2,3,4,5].
    // For target=6, arr[high]<target.
    // For target=0, arr[low]>target.
    // We can root out these edge cases right in step 1.
    while(low<=high && arr[low]<target && arr[high]>target]) {
        int index = low+((target-arr[low])*(high-low)/(arr[high]-arr[low]));
        if (arr[low] == arr[high]) {
            // All elements within the array are same.
            if (arr[low] == target) {  // OR (arr[end]==target)
                // All elements in the array:
                // - are same.
                // - are equal to the target.
                return low;
                break;
            }
            // All elements in the array:
            // - are same.
            // - are not the target.
            break;
        }

        if(arr[index]<target) {
            low = index+1;
        } else if(arr[index]>target) {
            high = index-1;
        } else {
            return index;
        }
    }
    // Element not found
    return -1;
}

int main() {
    // Array must be sorted
    int arr[maxLength] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    printf("Index: %d",interpolationSearch(arr, target));

    return 0;
}
