#include <stdio.h>
#include <math.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int karatsuba(int n1, int n2) {
    // If either of the numbers is single-digit, perform a simple multiplication. Otherwise, use the algorithm.
    // This logic also functions as the Base Condition.
    if (n1 < 10 || n2 < 10) {
        return n1 * n2;
    }

    // Calculate the number of digits in `n1` and `n2`.
    // `log_10 (1234+1)` gives us the number of digits in 1234.
    int size1 = max((int)log10(n1) + 1, (int)log10(n2) + 1);
    int size2 = size1 / 2;

    // Split the digits
    int a = n1 / (int)pow(10, size2);
    int b = n1 % (int)pow(10, size2);
    int c = n2 / (int)pow(10, size2);
    int d = n2 % (int)pow(10, size2);

    // Calculating intermediates
    int z0 = karatsuba(b, d);
    int z1 = karatsuba(a, c);
    int z2 = karatsuba(a + b, c + d) - z1 - z0;

    // Calculating result
    return z1 * (int)pow(10, 2 * size2) + z2 * (int)pow(10, size2) + z0;
}

int main() {
    int number1 = 1234;
    int number2 = 5678;
    printf("\nNumber 1: %d",number2);
    printf("\nNumber 2: %d",number1);
    printf("\nResult: %d\n", karatsuba(number1, number2));
    return 0;
}
