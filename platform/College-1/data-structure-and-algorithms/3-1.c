#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    char *Name;
    struct Node *next;
};

void addFront(struct Node **head, int data, char *str) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        return;
    }

    newNode->data = data;
    newNode->Name = str;
    newNode->next = *head;
    *head = newNode;
}

// void addBack(struct Node **head, int data) {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         fprintf(stderr, "Memory allocation failed.");
//         return;
//     }
//     newNode->data = data;
//     newNode->next = NULL;

//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }

//     struct Node *currentNode = *head;
//     while (currentNode->next != NULL) {
//         currentNode = currentNode->next;
//     }
//     currentNode->next = newNode;
// }

void traverse(struct Node *head) {
    struct Node *currentNode = head;
    while(currentNode != NULL) {
        printf("%d, %s -> ", currentNode->data,currentNode->Name);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    // addFront(&head,12);
    addFront(&head,14,"String");
    // addBack(&head,16);
    traverse(head);
    return 0;
}