#include<stdio.h>
#include<stdbool.h>
#define charStackSize 5
struct charStack {
    char arr[charStackSize];
    int top;
};

// Stack is full when top is 1 less than stack size.
bool isFull(struct charStack *stack) {
    return (stack->top==(charStackSize-1));
}

// Stack is empty when top is -1.
bool isEmpty(struct charStack *stack) {
    return (stack->top==-1);
}

void initStack(struct charStack *stack) {
    stack->top=-1;
}

void push(struct charStack *stack, char ch) {
    if(isFull(stack)) {
        printf("\nStack Overflow");
        return;
    }

    stack->top++;
    stack->arr[stack->top]=ch;
    printf("\nElement pushed: %c",ch);
}

void pop(struct charStack *stack) {
 
    if(isEmpty(stack)) {
        printf("\nStack Underflow");
        return;
    }

    printf("\nElement popped: %c",stack->arr[stack->top]);
    stack->top--;
}

void peek(struct charStack *stack) {
    if(isEmpty(stack)) {
        printf("\nStack Underflow");
        return;
    }

    printf("\nElement on top: %c",stack->arr[stack->top]);
}

int main() {
    // structure `name` is created and initialized.
    struct charStack name;
    initStack(&name);

    // INPUT: `%5s` means only take 5 elements, reject the rest.
    printf("Enter name: ");
    scanf("%5s",name.arr);
    
    // Pushing to stack, one character at a time.
    for(int iter=0;iter<charStackSize;iter++) {
        push(&name,name.arr[iter]);
    }

    // Triggers Overflow
    push(&name,'e');

    printf("\n");

    // Peeking at the topmost element.
    peek(&name);

    printf("\n");

    // Popping from stack, one character at a time.
    for(int iter=0;iter<charStackSize;iter++) {
        pop(&name);
    }

    // Triggers Underflow
    pop(&name);
}