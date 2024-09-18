#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxStrLen 5

void merge(char *inArr, int low, int mid, int high) {
    int left = low;
    int right = mid+1;
    char *tempArr = (char *)malloc(sizeof(char)*(high-low+1));
    int tempIter = 0;
    while(left<=mid && right<=high) {
        if(inArr[left]<=inArr[right]) {
            tempArr[tempIter] = inArr[left];
            left++;
        } else {
            tempArr[tempIter] = inArr[right];
            right++;
        }
        tempIter++;
    }
    
    while(left<=mid) {
        tempArr[tempIter] = inArr[left];
        tempIter++;
        left++;
    }
    
    while(right<=high) {
        tempArr[tempIter] = inArr[right];
        tempIter++;
        right++;
    }
    
    for(int iter=low;iter<=high;iter++) {
        inArr[iter] = tempArr[iter-low];
    }
    free(tempArr);
}

void mergeSort(char *inArr, int low, int high) {
    // Base case
    if(low==high) {
        return;
    }
    
    int mid = low+(high-low)/2;
    mergeSort(inArr, low, mid);
    mergeSort(inArr, mid+1, high);
    
    merge(inArr, low, mid, high);
}

void printArr(char *inArr) {
    for(int index=0;index<maxStrLen;index++) {
        printf("%c, ",inArr[index]);
    }
    printf("\\0 \n");
}

int main() {
    char *inName = (char *)malloc(sizeof(char)*5);
    printf("Enter your name: "); scanf("%s",inName);
    printf("Original  array: "); printArr(inName);
    mergeSort(inName,0,maxStrLen-1);
    printf("Sorted array: "); printArr(inName);
    return EXIT_SUCCESS;
}
