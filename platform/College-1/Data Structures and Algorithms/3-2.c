#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    int empno;
    int salary;
    struct stackNode *next;
};

void push(struct stackNode **head, int inEmpno, int inSalary) {
    struct stackNode *newNode = (struct stackNode *)malloc(sizeof(struct stackNode));
    newNode->empno=inEmpno;
    newNode->salary=inSalary;
    newNode->next=NULL;
    if(*head==NULL) {
        *head = newNode;
        return;
    }
    struct stackNode *currentNode = *head;
    while(currentNode->next!=NULL) {
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
}

void checkAndPop(struct stackNode **head) {
    if(*head==NULL) {
        printf("Stack underflow.");
        return;
    } else if((*head)->next==NULL) {
        if((*head)->salary > 3000) {
            free(*head);
            *head = NULL;
        }
        return;
    }

    struct stackNode *prevNode = *head;
    struct stackNode *currentNode = (*head)->next;
    while(currentNode!=NULL) {
        if(currentNode->salary>3000) {
            struct stackNode *temp = currentNode;
            prevNode->next = currentNode->next;
            currentNode = currentNode->next;
            free(temp);
        } else {
            prevNode=currentNode;
            currentNode=currentNode->next;
        }
    }
}

void traverse(struct stackNode *head) {
    if(head==NULL) {
        printf("Stack underflow.");
        return;
    }
    struct stackNode *currentNode = head;
    while(currentNode!=NULL) {
        printf("\nEmployee No: %d, Salary: %d",currentNode->empno,currentNode->salary);
        currentNode=currentNode->next;
    }
    printf("\n");
}

int main() {
    char choice='y';
    int inEmpno;
    int inSalary;
    struct stackNode *head = NULL;
    while(choice=='y') {
        printf("Enter Employee No: "); scanf("%d",&inEmpno);
        printf("Enter salary: "); scanf("%d",&inSalary);
        push(&head,inEmpno,inSalary);
        printf("Enter 'y' to enter more values: "); scanf(" %c",&choice);
    }

    printf("Original stack: "); traverse(head);
    checkAndPop(&head);
    printf("Stack after popping invalid elements: "); traverse(head);
    return 0;
}
