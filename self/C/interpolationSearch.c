#include <stdio.h>
#define maxLength 10

int interpolationSearch(int *arr, int target) {
    int low = 0;
    int high = maxLength-1;
    while(low<=high) {
        int index = low+((target-arr[low])*(high-low)/(arr[high]-arr[low]));
        if(arr[index]<target) {
            low = index+1;
        } else if(arr[index]>target) {
            high = index-1;
        } else {
            return index;
        }
    }
    return -1;
}

int main() {
    int arr[maxLength] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target;

    printf("Enter the target value: ");
    scanf("%d", &target);

    printf("Index: %d",interpolationSearch(arr, target));

    return 0;
}