#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    omp_set_num_threads(2);
    int num1,num2,num3;
    int smallest, largest;
    double start,end;
    start = omp_get_wtime();
    printf("Enter first number: ");  scanf("%d",&num1);
    printf("Enter second number: "); scanf("%d",&num2);
    printf("Enter third number: ");  scanf("%d",&num3);
    # pragma omp parallel 
    {
        int tID = omp_get_thread_num();
        if(tID==0) {
            if(num1<=num2 && num1<num3) {
                smallest = num1;
            } else if(num2<=num1 && num2<=num3) {
                smallest = num2;
            } else {
                smallest = num3;
            }
        } else if(tID==1) {
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
    end = omp_get_wtime();
    printf("\nSmallest number: %d",smallest);
    printf("\nLargest number: %d",largest);
    printf("\n\nExecution Time: %lf",(end-start));

    printf("\n");
    return EXIT_SUCCESS;
}
