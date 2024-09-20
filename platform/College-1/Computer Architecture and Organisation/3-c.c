#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Master Thread
    int num1,num2,num3;
    int smallest, largest;
    printf("Enter first number: ");  scanf("%d",&num1);
    printf("Enter second number: "); scanf("%d",&num2);
    printf("Enter third number: ");  scanf("%d",&num3);
    # pragma omp parallel sections
    {
        # pragma omp section 
        {
            if(num1<=num2 && num1<num3) {
                smallest = num1;
            } else if(num2<=num1 && num2<=num3) {
                smallest = num2;
            } else {
                smallest = num3;
            }
        }

        # pragma omp section 
        {
            if(num1>=num2 && num1>=num3) {
                largest = num1;
            } else if(num2>=num1 && num2>=num3) {
                largest = num2;
            } else {
                largest = num3;
            }
        }
    }
    // Master Thread
    printf("Smallest number: %d",smallest);
    printf("\nLargest number: %d",largest);
    printf("\n");
    return EXIT_SUCCESS;
}
