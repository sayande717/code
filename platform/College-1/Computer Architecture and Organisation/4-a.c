#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#define N 1024

// CUDA kernel, for parallel execution on an nVidia GPU.
__global__ void inc_vectors(double *a, int N) {
    // blockIdx.x: Built-in variable in CUDA that gives the block index in the x-dimension.
    int id = blockIdx.x;
    if (id < N) {
        a[id] = a[id] + 1;
    }
}

int main() {
    size_t bytes = N * sizeof(double);
    // A = Array on CPU memory | d_A = Array on GPU memory
    double* A = (double*)malloc(bytes);
    double* d_A;

    // Allocate memory for 1-D array d_A, on the GPU.
    cudaMalloc(&d_A, bytes);

    // Modify data
    for (int i = 0; i < N; i++) {
        A[i] = 1.0; 
    }

    // Copy data from CPU memory -> GPU memory
    cudaMemcpy(d_A, A, bytes, cudaMemcpyHostToDevice);


    dim3 gridsize(N);
    dim3 blocksize(1);
    // CUDA kernel is launched, with N blocks and 1 thread per block.
    inc_vectors<<<gridsize, blocksize>>>(d_A, N);
    // Copy data (back) from GPU -> CPU memory.
    cudaMemcpy(A, d_A, bytes, cudaMemcpyDeviceToHost);

    // Free memory on both CPU & GPU
    cudaFree(d_A);
    free(A);
    return 0;
}