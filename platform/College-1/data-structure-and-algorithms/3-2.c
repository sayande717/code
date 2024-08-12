#include<stdio.h>
#include<stdlib.h>

struct stackNode {
    char *name;
    int sal;
    struct Node *next;
};

void input(char *inName, int inSal) {
    printf("\nEnter Name: "); scanf("%s",inName);
    printf("Enter Registration No: "); scanf("%d",inSal);
}

void push(struct stackNode **head, char *inName, int inSal) {
    if(inSal > 3000) {
        return;
    }
    
    struct stackNode *currentNode = head;
    struct stackNode *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->name=inName;
    newNode->reg=inSal;
    newNode->next=NULL;
    
    
    if(currentNode==NULL) {
        currentNode = newNode;
        return;
    }
    
    while(currentNode->next!=NULL) {
        currentNode = currentNode->next;
    }
    
    currentNode->next = newNode;
}	 	  	 	   	      	 	    	   	      	    	 	

void traverse(struct Node *head) {
    struct Node *currentNode = head;
    
    while(currentNode!=NULL) {
        printf("Name: %s, Reg: %s || ",currentNode->name,currentNode->reg);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void pop(struct stackNode *head) {
    struct Node *prevNode = *head;
    if(*prevNode->next==NULL) {
        prevNode==NULL;
        return;
    }
    struct stackNode *currentNode = prevNode->next;

    while(currentNode->next!=null) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = NULL;
}

int main() {
    int n;
    char *name = (char *)malloc(sizeof(char));
    int sal;
    struct stackNode *head;
    printf("Enter n: "); scanf("%d",&n);
    
    // INPUT
    for(int iter=0;iter<n;iter++) {
        input(name,sal);
        // Salary is checked while pushing to stack.
        push(&head,name,sal);
    }	 	  	 	   	      	 	    	   	      	    	 	

    
    // OUTPUT
    traverse(head);
    
    // Demonstrating pop
    pop(&head);
    
    free(name);
}