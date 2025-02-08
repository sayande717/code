#include <stdio.h>
#include <stdlib.h>

int fibo_generic(int n) {
    // Base Case
    if(n==1 || n==2) {
        return 1;
    }
    return fibo_generic(n-1)+fibo_generic(n-2);
}

// An array of size (n+1) is created, because fibo_dynamic(n) will be stored in arr[n]. So, the full range of 0 to n (not n-1) is needed.
int fibo_dynamic(int n, int* arr) {
    int result;
    // If sub-problem solution exists, return it.
    if(arr[n] != 0) {
        return arr[n];
    }
    // Base Case
    if(n==1 || n==2) {
        result = 1;
        return result;
    }
    result = fibo_dynamic(n-1,arr)+fibo_dynamic(n-2,arr);
    arr[n] = result;
    
    return result;
}

int main() {
    int n;
    printf("Enter n: "); scanf("%d",&n);
    int* arr = (int*)calloc((n+1),sizeof(int));
    printf("\nGeneric: %d",fibo_generic(n));
    printf("\nDynamic: %d",fibo_dynamic(n,arr));
    
    free(arr);
    printf("\n");
    return EXIT_SUCCESS;
}