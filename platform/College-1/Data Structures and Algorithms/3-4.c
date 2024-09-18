#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct listNode {
    char *name;
    double overs;
    int count;
    struct listNode *next;
};

void addToBeginning(struct listNode **head, char *inName, double inOvers) {
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
    newNode->name = (char *)malloc(strlen(inName) + 1);
    newNode->overs = inOvers;
    newNode->next = NULL;
    strcpy(newNode->name, inName);
    if((*head)==NULL) {
        newNode->count=1;
        (*head) = newNode;
        return;
    }

    // update number of elements
    newNode->count=(*head)->count+1;
    // Add to beginning
    newNode->next=(*head);
    (*head)=newNode;
}

void printList(struct listNode *head) {
    if(head == NULL) {
        fprintf(stderr,"List empty");
        return;
    }

    struct listNode *currentNode = head;
    while(currentNode != NULL) {
        printf("\nName: %s, Overs: %f, Count: %d", currentNode->name, currentNode->overs, currentNode->count);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct listNode *head = NULL;
    addToBeginning(&head,"Sample Name 1",20);
    addToBeginning(&head,"Sample Name 2",25.03);
    addToBeginning(&head,"Sample Name 3",30.05);
    printList(head);
    return 0;
}