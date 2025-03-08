#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxExpLen 20

typedef struct listNode {
    float base;
    int exponent;
    struct listNode *next;
} linkedList;

void addToLast(linkedList **head, int inBase, int inExponent) {
    linkedList *newNode = (linkedList *)malloc(sizeof(linkedList));
    if(newNode==NULL) {
        fprintf(stderr,"Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    newNode->base = inBase;
    newNode->exponent = inExponent;
    newNode->next = NULL;

    if((*head)==NULL) {
        (*head)=newNode;
        return;
    }

    linkedList *currentNode = (*head);
    while (currentNode->next!=NULL) {
        currentNode=currentNode->next;
    }
    currentNode->next = newNode;
}

// fill the linked list with data, return the max exponent value
int fillExpList(linkedList **inList, char *inStr) {
    float base = 0.0;
    int exponent = 0;
    char *token = strtok(inStr, "+-");
    while (token != NULL) {	 	  	 	   	      	 	    	   	      	    	 	
        for(int iter=0;iter<strlen(token);iter++) {
            // Example: token="45x^2"
            if(token[iter]=='x') {
                base = atoi(token);             // range: `45x^2` -> `45`
                exponent = atoi(token+iter+2);  // range: `45x^2` -> `2`
                addToLast(inList,base,exponent);
            }
        }
        token = strtok(NULL, "+");
    }
}

int fillResultList(linkedList *inHead1, linkedList *inHead2, linkedList **inHeadResult) {
    linkedList *currNode1 = inHead1;
    linkedList *currNode2 = inHead2;
    while(currNode1!=NULL && currNode2!=NULL) {
        // Perform the polynomial addition, add to the result list.
        addToLast(inHeadResult,(currNode1->base+currNode2->base),currNode1->exponent);
        currNode1=currNode1->next;
        currNode2=currNode2->next;
    }
}

void printList(linkedList *inList) {
    if(inList==NULL) {
        return;
    }
    linkedList *currentNode = inList;
    while (currentNode != NULL) {
        printf("%.2fx^%d+", currentNode->base, currentNode->exponent);
        currentNode = currentNode->next;
    }
}

int main() {
    char *exp1 = (char *)malloc(sizeof(char)*maxExpLen);
    char *exp2 = (char *)malloc(sizeof(char)*maxExpLen);
    if(exp1==NULL || exp2==NULL) {	 	  	 	   	      	 	    	   	      	    	 	
        fprintf(stderr,"Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    linkedList *expList1 = NULL;
    linkedList *expList2 = NULL;
    linkedList *resultList = NULL;

    printf("Enter expression 1: "); scanf("%s", exp1);
    printf("Enter expression 2: "); scanf("%s", exp2);

    fillExpList(&expList1,exp1);
    fillExpList(&expList2,exp2);
    fillResultList(expList1,expList2,&resultList);
    printf("Result: "); printList(resultList);

    return EXIT_SUCCESS;
}