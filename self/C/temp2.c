#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

int a;
int b;
int result;

void input(int inVar0, int inVar1) {
    printf("Enter two numbers: ");
    scanf("%d %d", &inVar0, &inVar1);
    return;

    // statement
    // statement
    
}

void calc() {
    result=a*b;
}

int main() {
    int var0, var1;
    input(var0, var1);
    calc();
    printf("Result: %d\n", result);
    
}















// // Function with no arguments and no return value
// void addNumbers() {
//     int num1, num2, sum;
    
//     printf("Enter two numbers: ");
//     scanf("%d %d", &num1, &num2);
    
//     sum = num1 + num2;
    
//     printf("Sum: %d\n", sum);
// }

// // Function with no arguments but with a return value
// int multiplyNumbers() {
//     int num1, num2, product;
    
//     printf("Enter two numbers: ");
//     scanf("%d %d", &num1, &num2);
    
//     product = num1 * num2;
    
//     return product;
// }

// // Function with arguments and a return value
// int divideNumbers(int num1, int num2) {
//     int quotient;
    
//     quotient = num1 / num2;
    
//     return quotient;
// }


// // Function with arguments but no return value
// void subtractNumbers(int num1, int num2) {
//     int difference;
    
//     difference = num1 - num2;
    
//     printf("Difference: %d\n", difference);
// }

// int main() {
//     addNumbers();

//     int result = multiplyNumbers();
//     printf("Product: %d\n", result);
    
//     int num1, num2;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &num1, &num2);
//     subtractNumbers(num1, num2);
    
//     int quotient = divideNumbers(num1, num2);
//     printf("Quotient: %d\n", quotient);

//     return 0;
// }