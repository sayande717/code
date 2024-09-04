#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxExpLen 20
/* Assumptions:
   - The expression will be a standard polynomial expression: 25x^2+50x^1-2x^0
   - `x^0` will be added at last, which is the same as `1`.
*/

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

int findMax(int inNum1, int inNum2) {
    return (inNum1>=inNum2)?inNum1:inNum2;
}

// fill the linked list with data, return the max exponent value
int fillList(linkedList **inList, char *inStr) {
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

void printList(linkedList *inList) {
    if(inList==NULL) {
        return;
    }

    linkedList *currentNode = inList;
    while (currentNode != NULL) {
        printf("%.2fx^%d ", currentNode->base, currentNode->exponent);
        currentNode = currentNode->next;
    }
}

int main() {
    char *exp1 = (char *)malloc(sizeof(char)*maxExpLen);
    char *exp2 = (char *)malloc(sizeof(char)*maxExpLen);
    linkedList *expList1 = NULL;
    linkedList *expList2 = NULL;

    printf("Enter expression 1: "); scanf("%s", exp1);
    printf("Enter expression 2: "); scanf("%s", exp2);
    fillList(&expList1,exp1);
    fillList(&expList2,exp2);

    printList(expList1);
    printf("\n");
    printList(expList2);
    
    return EXIT_SUCCESS;
}