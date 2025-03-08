#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define maxQueueLength 10
#define maxNameLength 30

struct queueNode {
    char *custName;
    int custID;
    int front;
    int rear;
    bool checkedIn;
    struct queueNode *next;
};

void initQueue(struct queueNode **head) {
    (*head)=(struct queueNode *)malloc(sizeof(struct queueNode));
    (*head)->front=-1;
    (*head)->rear=-1;
    (*head)->next=NULL;
}

bool isEmpty(struct queueNode *head) {
    if(head==NULL) {
        fprintf(stderr,"Queue doesn't exist.");
        return 0;
    }
    
    if(head->front==-1 && head->rear==-1) {
        return 1;
    }

    return 0;
}

bool isFull(struct queueNode *head) {
    if(head==NULL) {
        fprintf(stderr,"Queue doesn't exist.");
        return 0;
    }

    if((head->rear%maxQueueLength+1)==head->front) {
        return 1;
    }

    return 0;
}

int enQueue(struct queueNode **head, char *inName, int inID) {
    struct queueNode *newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    newNode->custName = (char *)malloc(strlen(inName) + 1);
    strcpy(newNode->custName,inName);
    newNode->custID=inID;
    newNode->next=NULL;

    if(isEmpty(*head)) {
        *head = newNode;
        (*head)->front = 0;
        (*head)->rear = 0;
        return true;
    } else if(isFull(*head)) {
        return false;
    }

    struct queueNode *currentNode = *head;
    while(currentNode->next!=NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next=newNode;
    return true;
}

int deQueue(struct queueNode **head) {
    if(isEmpty(*head)) {
        return -1;
    }
        (*head)->front = -1;
        (*head)->rear = -1;
        free(*head);
        *head = NULL;
    struct queueNode *currentNode = (*head);
    int outID = (*head)->custID;
    if ((*head)->next == NULL) {
        (*head) = NULL;
    } else {
        (*head) = (*head)->next;
    }
    free(currentNode);
    return outID;
}

char *searchQueue(struct queueNode *head, int inID) {
    if (isEmpty(head)) {
        return NULL;
    }
    struct queueNode *currentNode = head;
    while (currentNode != NULL) {
        if (inID == currentNode->custID) {
            return currentNode->custName;
        }
        currentNode = currentNode->next;
    }
    return "0";
}

int main() {
    char *inName = (char *)malloc(sizeof(char)*(maxNameLength+1));
    int inID;
    struct queueNode *custDB = NULL;
    struct queueNode *checkInDB = NULL;
    initQueue(&custDB);
    initQueue(&checkInDB);
    
    int choice0;
    char choice1 = 'y';
    while(choice1=='y') {
        printf("\nOptions: \n");
        printf("1. Enroll\n");
        printf("2. Check-in\n");
        printf("3. Check-out\n");
        printf("Enter: "); scanf("%d", &choice0);

        switch(choice0) {
            case 1:
                printf("<--- Enrollment --->");
                printf("\nEnter Customer name: "); scanf("%s",inName);
                printf("Enter Customer ID: "); scanf("%d",&inID);
                if(enQueue(&custDB,inName,inID)) {
                    printf("Customer enrolled succesfully.");
                } else {
                    printf("Customer enrollment failed.");
                }
                break;

            case 2:
                printf("Enter Customer ID: "); scanf("%d",&inID);
                if(searchQueue(custDB,inID)!="0") {
                    enQueue(&checkInDB,searchQueue(custDB,inID),inID);
                    printf("Customer checked-in succesfully.");
                } else {
                    printf("Customer isn't registered.");
                }
                break;

            case 3:
                int deQueueID = deQueue(&checkInDB);
                if(deQueueID!=-1) {
                    printf("Due to FIFO, Customer ID %d was checked out.",deQueueID);
                } else {
                    printf("Customer hasn't checked in.");
                }
                break;
            default:
                printf("Enter the correct option.");
                break;
        }
        printf("\nEnter 'y' to continue: "); scanf(" %c",&choice1);
    }
}