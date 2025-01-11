#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#define MAX_SIZE 1000

__global__ void kernel_add(int* v1, int* v2, int* vRes) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    if(index<MAX_SIZE) {
        vRes[index] = v1[index] + v2[index];
    }
}

int main() {
    float elapsed_time;
    size_t size = sizeof(int)*MAX_SIZE;

    // Allocate CPU Memory
    int* arr1 = (int*)malloc(size);
    int* arr2 = (int*)malloc(size);
    int* arrRes = (int*)malloc(size);

    // Allocate GPU Memory
    int *Darr1,*Darr2,*DarrRes;
    cudaMalloc(&Darr1,size);
    cudaMalloc(&Darr2,size);
    cudaMalloc(&DarrRes,size);
    
    if (arr1 == NULL || arr2 == NULL || arrRes == NULL || Darr1 == NULL || Darr2 == NULL || DarrRes == NULL) {
        fprintf(stderr, "Failed to allocate memory on host\n");
        return 1;
    }

    for(int index=0;index<MAX_SIZE;index++) {
        arr1[index] = index;
        arr2[index] = index * MAX_SIZE;
    }

    // Copy data to GPU
    cudaMemcpy(Darr1,arr1,size,cudaMemcpyHostToDevice);
    cudaMemcpy(Darr2,arr2,size,cudaMemcpyHostToDevice);
    
    // START events
    cudaEvent_t start,stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // START Recording time
    cudaEventRecord(start,0);
    dim3 threads_per_block(256);
    dim3 blocks_per_grid((MAX_SIZE + threads_per_block.x - 1) / threads_per_block.x);
    kernel_add<<<blocks_per_grid,threads_per_block>>>(Darr1,Darr2,DarrRes);
    // STOP Recording time
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    cudaMemcpy(arrRes,DarrRes,size,cudaMemcpyDeviceToHost);
    cudaEventElapsedTime(&elapsed_time,start,stop);
    
    printf("Parallel Execution Time: %f",elapsed_time);

    // Free Memory
    free(arr1);
    free(arr2);
    free(arrRes);
    cudaFree(Darr1);
    cudaFree(Darr2);
    cudaFree(DarrRes);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    printf("\n");
    return EXIT_SUCCESS;
}