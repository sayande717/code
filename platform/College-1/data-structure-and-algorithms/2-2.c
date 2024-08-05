#include<stdio.h>
#include<stdbool.h>
#define intStackSize 10

struct intStruct {
    int decimel[intStackSize];
    int top;
};

void initStack(struct intStruct *stack) {
    stack->top=-1;
}

bool isFull(struct intStruct *stack) {
    if(stack->top == (sizeof(stack->decimel)/sizeof(stack->decimel[0])-1)) {
        return true;
    }
    return false;
}

bool isEmpty(struct intStruct *stack) {
    if(stack->top==-1) {
        return true;
    }
    return false;
}

void push(struct intStruct *stack, int digit) {
    if(isFull(stack)) {
        printf("\nStack overflow");
        return;
    }
    stack->top = stack->top+1;
    stack->decimel[stack->top] = digit;
}

void popAll(struct intStruct *stack) {
    if(isEmpty(stack)) {
        printf("\nStack underflow");
        return;
    }

    printf("Popping elements till stack is empty (binary): ");
    
    while(stack->top>-1) {
        printf("%d",stack->decimel[stack->top]);
        stack->top=stack->top-1;
    }
}

int main() {
    struct intStruct convertor;
    initStack(&convertor);

    int decimel;
    printf("Enter a decimel integer: ");
    scanf("%d",&decimel);

    while(decimel!=0) {
        push(&convertor,decimel%2);
        decimel = decimel/2;
    }

    // Pop all elements, ie display the result.
    popAll(&convertor);
    printf("\n");

    return 0;
}
