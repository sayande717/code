#include <stdio.h>
#include <stdlib.h>

void swapByValue(int inVar1, int inVar2) {
    int temp = inVar1;
    inVar1 = inVar2;
    inVar2 = temp;
}

void swapByReference(int *inVar1, int *inVar2) {
    int temp = *inVar1;
    *inVar1 = *inVar2;
    *inVar2 = temp;
}

int main() {
    int num1 = 5;
    int num2 = 20;

    int *x = &num1;
    int *y = &num2;
    
    // int *x = &num1;
    // printf("Memory address of num1: %p\n", &num1);
    // printf("Memory address of x: %p\n", x);
    
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    swapByValue(num1, num2);
    printf("After swapping by value: num1 = %d, num2 = %d\n", num1, num2);

    swapByReference(&num1,&num2);
    printf("After swapping by reference: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
