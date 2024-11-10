#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct queueNode {
    char *name;
    int hNo;
    int days;
    struct queueNode *next;
};

void enQueue(struct queueNode **head, char *inName , int inHno, int inAdmitDate) {
    struct queueNode *newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    // Storing values in node.
    newNode->name = (char *)malloc(sizeof(strlen(inName))+1);
    strcpy(newNode->name,inName);
    newNode->hNo = inHno;
    newNode->days = inAdmitDate;
    newNode->next = NULL;
    
    if ((*head) == NULL) {
        (*head) = newNode;
        return;
    }

    struct queueNode *currentNode = *head;
    while(currentNode->next!=NULL) {
        currentNode=currentNode->next;
    }

    currentNode->next=newNode;
}

void checkAndDeQueue(struct queueNode **head) {
    if ((*head) == NULL) {
        printf("Queue underflow.\n");
        return;
    } else if((*head)->next == NULL && (*head)->days > 3) {
        // Free space for *head..
        struct queueNode *temp = *head;
        (*head)=NULL;
        free(temp);
        return;
    }

    struct queueNode *prevNode = *head;
    struct queueNode *currentNode = (*head)->next;
    while(currentNode!=NULL) {
        if(currentNode->days > 3) {
            // Free space for currentNode.
            struct queueNode *temp = currentNode;
            prevNode->next = currentNode->next;
            currentNode=currentNode->next;
            free(temp);
        }
    }
}

void traverse(struct queueNode *head) {
    struct queueNode *currentNode = head;
    if (currentNode == NULL) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Traversing queue:\n");
    while (currentNode != NULL) {
        printf("Patient Name: %s, Hospital Number: %d, Number of days: %d\n", currentNode->name, currentNode->hNo, currentNode->days);
        currentNode = currentNode->next;
    }
}

int main() {
    char choice='y';
    char *inName=(char *)malloc(sizeof(char));
    int inHno;
    int inDays;
    struct queueNode *head = NULL;
    while(choice=='y') {
        printf("Enter Patient Name: "); scanf("%s",inName);
        printf("Enter Hospital Number: "); scanf("%d",&inHno);
        printf("Enter number of days since admitted: "); scanf("%d",&inDays);
        enQueue(&head,inName, inHno, inDays);
        printf("Enter 'y' to enter more values: "); scanf(" %c",&choice);
    }

    traverse(head);
    checkAndDeQueue(&head);
    traverse(head);
    return 0;
}
