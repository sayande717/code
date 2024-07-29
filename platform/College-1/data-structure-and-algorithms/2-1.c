/* Implementing a stack in C:
    - A stack is implemented in the form of a structured array.
    - First, initialize the structure with the array and top.
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct charStack {
    char arr[30];
    int top;
} name;

// Variable `*stack` points to nameStack, which is of type `struct`, is created.
void init(struct charStack *nameStack) { // (nameStack *stack)
    nameStack->top = -1;
}

bool isEmpty(struct charStack *nameStack) {
    return (nameStack->top==-1);
}

bool isFull(struct charStack *nameStack) {
    return (nameStack->top==sizeof(nameStack->arr)/sizeof(nameStack->arr[0])-1);
}

bool push(struct charStack *nameStack,char ch) {

    if(isFull(nameStack)) {
        printf("Stack overflow");
        return false;
    }

    nameStack->top = nameStack->top + 1;
    nameStack->arr[nameStack->top] = ch;
    return true;
}	 	  	 	   	      	 	    	   	      	    	 	

bool pop(struct charStack *nameStack) {
    if(isEmpty(nameStack)) {
        printf("Stack underflow");
        return false;
    }
    
    nameStack->top = nameStack->top-1;
    return true;
}

bool display(struct charStack *nameStack) {
    char *index = nameStack->arr;
    
    for(int iter=0;iter<nameStack->top;iter++) {
        printf("%c",*index);
        index++;
    }
    return true;
}


int main() {
    
    // INPUT
    printf("Enter name: ");
    scanf("%29s",name.arr);
    
    init(&name);
    printf("\npush status: %b",push(&name,'a'));
    //printf("\npop status: %b",pop(&name));
    display(&name);
    
}	 	  	 	   	      	 	    	   	      	    	 	

/*
char a[] = "hello";
char *index = a;
printf("%c",*index);
index++;
*/
