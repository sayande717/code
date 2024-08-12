#include<stdio.h>
#include<stdlib.h>

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
    newNode->name=inName;
    newNode->reg=inReg;
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

int main() {
    int n;
    char *name = (char *)malloc(sizeof(char));; 
    char *reg = (char *)malloc(sizeof(char));;
    struct Node *head;
    printf("Enter n: "); scanf("%d",&n);
    for(int iter=0;iter<n;iter++) {
        input(name,reg);
        addToEnd(&head,name,reg);
    }
    
    traverse(head);
    free(name); free(reg);
}
