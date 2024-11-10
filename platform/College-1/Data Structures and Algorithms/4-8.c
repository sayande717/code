#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node {
    char *name;
    char *regNo;
    int age;
    struct node *next;
} listNode;

bool isEmpty(listNode *head) {
   return (head==NULL); 
}

// isFull() check is not needed, since it is never really full (except if the system is out of memory).

void insertNode(listNode **head, char *inName, char *inRegNo, int inAge) {
    listNode *newNode = (listNode *)malloc(sizeof(listNode));
    newNode->name = (char *)malloc(sizeof(char)*strlen(inName)+1);
    strcpy(newNode->name,inName);
    newNode->regNo = (char *)malloc(sizeof(char)*strlen(inRegNo)+1);
    strcpy(newNode->regNo,inRegNo);
    newNode->age=inAge;
    newNode->next=NULL;

    if(isEmpty((*head))) {
        (*head) = newNode;
        newNode->next = (*head);
        return;
    }

    listNode *headNode = (*head);
    listNode *currentNode = (*head);

    while(currentNode->next!=headNode) {
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
    newNode->next=headNode;
}

bool removeNode(listNode **head, int targetNode) {
    // Handling no nodes, 1 node.
    if(isEmpty((*head))) {
        return false;
    }

    if((*head)->next==(*head) && targetNode==1) {
        listNode *tempNode = (*head);
        (*head)=(*head)->next;
        free(tempNode);
        return true;
    }

    int count=1;
    listNode *previousNode = (*head);
    listNode *currentNode = (*head)->next;
    listNode *headNode = (*head);
    int target = (targetNode-1);
    while(currentNode!=headNode && count!=(target)) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        count++;
    }

    // List end reached before target node was reached.
    if(currentNode==headNode) {
        return false;
    }

    previousNode->next = currentNode->next;
    free(currentNode);
    return true;
}

void displayList(listNode *head) {
    if(isEmpty(head)) {
        printf("\nNo elements in linked list.");
        return;
    }

    listNode *currentNode = head;
    listNode *headNode = head;
    printf("\nLinked List: ");
    // IMPORTANT: Here, current node = head node at first, so we need a do-while loop.
    do {
        printf("(%s | %s | %d) -> ",currentNode->name,currentNode->regNo,currentNode->age);
        currentNode = currentNode->next;
    } while(currentNode!=headNode);
    printf("HEAD\n");
}

void freeNodes(listNode **head) {
    if(isEmpty((*head))) {
        return;
    }
    listNode *currentNode= (*head);
    listNode *nextNode;
    // Freeing the head first would result in null pointer when the last node's next needs to be reached.
    // So, we start freeing from head->next. We free the head at last.
    do {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    } while(currentNode!=(*head));

    free((*head));
}

int main() {
    listNode *head = NULL;
    char *name = (char *)malloc(20);
    char *regNo = (char *)malloc(10);
    int age;
    
    char choice = 'n';
    do {
        printf("\nEnter Name: "); scanf("%s",name);
        printf("Enter Registration Number: "); scanf("%s",regNo);
        printf("Enter Age: "); scanf("%d",&age);
        insertNode(&head,name,regNo,age);
        printf("Do you want to enter more values? "); scanf(" %c",&choice);
    } while(choice=='y');

    displayList(head);

    int n;
    printf("Enter the node number you want to remove (n): "); scanf("%d",&n);
    if(removeNode(&head,n)) {
        printf("Node removed succesfully.");
    } else {
        printf("Node doesn't exist.");
    }

    displayList(head);

    // free local variables
    free(name);
    free(regNo);

    return EXIT_SUCCESS;
}
