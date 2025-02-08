#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *newNode(int data) {
    // node* newNode: Create a node, then store it's pointer in newNode.
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// INPUT: A pointer to head.
void printList(struct node *head) {
    struct node *currentNode = head;
    while(currentNode!=NULL) {
        printf("%d -> ",currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

// INPUT: A pointer to a pointer to head.
// `**` deferences the pointer, so the modifications link back to the main variable.
void addToBeginning(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next=*head;
    
}

int main() {
    struct node *head = NULL;
    int value;
    printf("Enter data: ");
    scanf("%d",&value);

    head = newNode(value);
    struct node *Node2 = newNode(value+1);
    head->next = Node2;

    printList(head);

    free(head);
    free(Node2);
    return EXIT_SUCCESS;
}
