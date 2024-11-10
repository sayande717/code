#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_HEAP_SIZE 10

typedef struct {
    char data[MAX_HEAP_SIZE];
    int size;
} MaxHeap;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *heap, int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && heap->data[index] > heap->data[parentIndex]) {
        swap(&heap->data[index], &heap->data[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

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

void insert(MaxHeap *heap, char value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

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

void heapSort(MaxHeap *heap, char *sortedArray) {
    int originalSize = heap->size;
    for (int i = originalSize - 1; i >= 0; i--) {
        sortedArray[i] = extractMax(heap);
    }
}

int main() {
    MaxHeap heap;
    heap.size = 0;
    char name[MAX_HEAP_SIZE + 1];
    printf("Enter a name (max %d characters): ", MAX_HEAP_SIZE); scanf("%7s", name);
    for (int i = 0; i < strlen(name); i++) {
        insert(&heap, name[i]);
    }

    char sortedArray[strlen(name)];
    heapSort(&heap, sortedArray);
    for (int i = 0; i < strlen(name); i++) {
        printf("%c", sortedArray[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}