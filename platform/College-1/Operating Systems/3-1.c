#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
    int size;
    bool free;
    struct Block* next;
} block;

int maxSize = 0;

void initMemory(block** head, int size) {
    (*head) = (block*)malloc(sizeof(block));
    (*head)->free=1;
    (*head)->size = size;
    maxSize = size;
    (*head)->next = NULL;
}

block* createBlock(int size) {
    block* node = (block*)malloc(sizeof(block));
    node->size = size;
    node->free = 0;
    node->next = NULL;
    return node;
}

void* firstFit(block** head, int size) {
    block* current = *head;
    while(current != NULL) {
        if(current->free == 1 && current->size >= size) {
            current->free = 0;
            return (void*)(current + 1);
        }
        current = current->next;
    }

    // create a new block incase a suitable one is not found.
    block* newBlock = createBlock(size);
    current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newBlock;

    // Return the address of the newly allocated block
    return (void*)(newBlock + 1);
}

void* worstFit(block** head, int size) {
    block* current = *head;
    block* worstBlock = NULL;

    while (current != NULL) {
        if (current->free == 1 && current->size >= size) {
            if (worstBlock == NULL || current->size > worstBlock->size) {
                worstBlock = current;
            }
        }
        current = current->next;
    }

    if (worstBlock != NULL) {
        worstBlock->free = 0;
        return (void*)(worstBlock + 1);
    }

    // create a new block incase a suitable one is not found.
    block* newBlock = createBlock(size);
    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newBlock;

    return (void*)(newBlock + 1);
}

void* bestFit(block** head, int size) {
    block* current = *head;
    block* bestBlock = NULL;

    while (current != NULL) {
        if (current->free == 1 && current->size >= size) {
            if (bestBlock == NULL || current->size < bestBlock->size) {
                bestBlock = current;
            }
        }
        current = current->next;
    }

    if (bestBlock != NULL) {
        bestBlock->free = 0;
        return (void*)(bestBlock + 1);
    }

    // create a new block incase a suitable one is not found.
    block* newBlock = createBlock(size);
    current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newBlock;

    return (void*)(newBlock + 1);
}

void print(void* loc1, void* loc2, void* loc3) {
    printf("\nMemory Addresses: \
            \nLocation 1: %p \
            \nLocation 2: %p \
            \nLocation 3: %p",loc1,loc2,loc3);
}

void dealloc(void* ptr) {
    block* target = (block*)ptr-1;
    target->free=1;
}

void runner(int choice) {
    block* head = NULL;
    void* loc1 = NULL;
    void* loc2 = NULL;
    void* loc3 = NULL;
    initMemory(&head,maxSize);
    switch(choice) {
        case 1:
            loc1 = firstFit(&head,100);
            loc2 = firstFit(&head,200);
            loc3 = firstFit(&head,300);
            print(loc1,loc2,loc3);
        break;
        case 2:
            loc1 = bestFit(&head,100);
            loc2 = bestFit(&head,200);
            loc3 = bestFit(&head,300);
            print(loc1,loc2,loc3);
        break;
        case 3:
            loc1 = worstFit(&head,100);
            loc2 = worstFit(&head,200);
            loc3 = worstFit(&head,300);
            print(loc1,loc2,loc3);
        break;
        default:
            return;
    }
    free(head);
    dealloc(loc1);
    dealloc(loc2);
    dealloc(loc3);
}

int main() {
    int choice;
    printf("Using 3 data segments.");
    printf("\nEnter the Memory Management Allocation Strategy: \
            \n1. First Fit \
            \n2. Best Fit \
            \n3. Worst Fit \
            \nEnter choice: "); scanf("%d",&choice);
    runner(choice);
    printf("\n");

    return EXIT_SUCCESS;
}
