#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    int empno;
    int salary;
    int top;
    struct queueNode *next;
};

void enQueue(struct queueNode **head, int inEmpno, int inSalary) {
    struct queueNode *newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    newNode->empno = inEmpno;
    newNode->salary = inSalary;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        newNode->top = 0;
        return;
    }
    struct queueNode *currentNode = *head;
    while(currentNode->next!=NULL) {
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
    newNode->top = (*head)->top+1;
}

void deQueue(struct queueNode **head) {
    if (*head == NULL) {
        printf("Queue underflow.\n");
        return;
    }
    *head = (*head)->next;
}

void traverse(struct queueNode *head) {
    struct queueNode *currentNode = head;
    if (currentNode == NULL) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Traversing queue:\n");
    while (currentNode != NULL) {
        printf("Empno: %d, Salary: %d\n", currentNode->empno, currentNode->salary);
        currentNode = currentNode->next;
    }
}

int main() {
    char choice='y';
    int inEmpno;
    int inSalary;
    struct queueNode *head = NULL;
    while(choice=='y') {
        printf("Enter Employee No: "); scanf("%d",&inEmpno);
        printf("Enter salary: "); scanf("%d",&inSalary);
        enQueue(&head,inEmpno,inSalary);
        printf("Enter 'y' to enter more values: "); scanf(" %c",&choice);
    }

    traverse(head);
    deQueue(&head);
    traverse(head);
    return 0;
}