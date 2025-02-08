#include<stdio.h>
#include<stdlib.h>
#define maxElements 10

int linearSentinelSearch(int *arr, int target) {
    int backup = arr[maxElements-1];
    arr[maxElements-1] = target;
    
    int index = 0;
    while(arr[index]!=target) {
        index++;
    }

    arr[maxElements-1] = backup;

    // index < maxElement - 1: Index has stopped between 0 and n-2, so element is present.
    // arr[maxElements-1] == target: the last element of the array is the target.
    if(index < maxElements-1 || arr[maxElements-1] == target) {
        return index;
    } else {
        return -1;
    }
}

int main() {
    int target;
    int arr[maxElements] = {4,3,5,6,9,10,13,44,-2,-1};
    printf("Enter target: "); scanf("%d",&target);
    printf("Index: %d",linearSentinelSearch(arr,target));
    return 0;
}