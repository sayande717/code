#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char *name;
    char *reg;
    struct Node *next;
};

void input(char *inName, char *inReg) {
    printf("\nEnter Name: "); scanf("%s",inName);
    printf("Enter Registration No: "); scanf("%s",inReg);
}

void addToEnd(struct Node **head, char *inName, char *inReg) {
    struct Node *currentNode = *head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // To copy a string into another, first create a memory space for the new variable, then copy the string to it.
    newNode->name = (char *)malloc(strlen(inName) + 1);
    strcpy(newNode->name, inName);
    
    newNode->reg = (char *)malloc(strlen(inReg) + 1);
    strcpy(newNode->reg, inReg);
    newNode->next=NULL;
    if(currentNode==NULL) {
        *head = newNode;
        return;
    }
    
    while(currentNode->next!=NULL) {
        currentNode = currentNode->next;
    }
    
    currentNode->next = newNode;
}

void traverse(struct Node *head) {
    printf("\nTraversing: \n");
    struct Node *currentNode = head;
    while(currentNode!=NULL) {
        printf("Name: %s, Reg: %s \n",currentNode->name,currentNode->reg);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    char choice='y';
    char *name = (char *)malloc(sizeof(char));; 
    char *reg = (char *)malloc(sizeof(char));;
    struct Node *head;
    while(choice=='y') {
        input(name,reg);
        addToEnd(&head,name,reg);
        printf("Enter 'y' to enter more data: "); scanf(" %c",&choice);
    }
    
    traverse(head);
    free(name); free(reg);
}
