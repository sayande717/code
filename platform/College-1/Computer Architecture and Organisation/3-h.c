#include <stdio.h>
#include <stdlib.h>

int* prefix_sum(int* x, int size) {
    int* y = (int*)malloc(sizeof(int)*size);
    y[0] = x[0];
    
    # pragma omp parallel private(index) firstprivate(y)
    for(int index=1;index<size;index++) {
	y[index] = y[index-1]+x[index];
    }
    return y;
}

void fill_arr(int* arr, int size) {
    for(int index=0;index<size;index++) {
	arr[index] = index+1;
    }
}

void print_arr(int* arr, int size) {
    for(int index=0;index<size;index++) {
	printf("%d ",arr[index]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size: "); scanf("%d",&size);
    int* x = (int*)malloc(sizeof(int)*size);
    fill_arr(x,size);
    print_arr(prefix_sum(x,size),size);
    
    free(x);
    printf("\n");
    return EXIT_SUCCESS;
}
