#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_HEAP_SIZE 10

// Define a structure for MaxHeap
typedef struct {
    char data[MAX_HEAP_SIZE]; // Array to store heap elements
    int size; // Current size of the heap
} MaxHeap;

// Swaps the values pointed to by a and b
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the element at index up the heap until the max-heap property is restored
void heapifyUp(MaxHeap *heap, int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && heap->data[index] > heap->data[parentIndex]) {
        swap(&heap->data[index], &heap->data[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

// Moves the element at index down the heap until the max-heap property is restored
void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

// Adds a new value to the heap and restores the max-heap property
void insert(MaxHeap *heap, char value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Removes and returns the maximum value from the heap, then restores the max-heap property
char extractMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return '\0';
    }
    char root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Extracts elements from the heap one by one and stores them in sortedArray in sorted order
void heapSort(MaxHeap *heap, char *sortedArray) {
    int originalSize = heap->size;
    for (int i = originalSize - 1; i >= 0; i--) {
        sortedArray[i] = extractMax(heap);
    }
}