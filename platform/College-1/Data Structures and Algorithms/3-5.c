#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxSize 100

// Structure for stack node
struct stackNode {
    int top;
    char items[maxSize];
};

// Function to initialize stack
void initStack(struct stackNode *stack) {
    stack->top = -1;
}

// Function to check if stack is full
int isFull(struct stackNode *stack) {
    return stack->top == maxSize - 1;
}

// Function to check if stack is empty
int isEmpty(struct stackNode *stack) {
    return stack->top == -1;
}

// Function to push an item to stack
void push(struct stackNode *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from stack
char pop(struct stackNode *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void reverseString(char *str) {
    int iter, jter;

    for (iter = 0, jter = strlen(str) - 1; iter < jter; iter++, jter--) {
        char temp = str[iter];
        str[iter] = str[jter];
        str[jter] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char *infix, char *prefix) {
    int i, j;
    struct stackNode stack;
    initStack(&stack);

    // Reverse the infix expression
    reverseString(infix);

    // Traverse the reversed infix expression
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        // If the current character is an operand, add it to the prefix expression
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        }
        // If the current character is an opening parenthesis, push it to the stack
        else if (infix[i] == ')') {
            push(&stack, infix[i]);
        }

        // If the current character is an operator
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            // Pop operators from the stack until an opening parenthesis or an operator with lower precedence is encountered
            while (!isEmpty(&stack) && getPrecedence(infix[i]) < getPrecedence(stack.items[stack.top])) {
                prefix[j++] = pop(&stack);
            }
            // Push the current operator to the stack
            push(&stack, infix[i]);
        }
        // If the current character is a closing parenthesis, pop operators from the stack until an opening parenthesis is encountered
        else if (infix[i] == '(') {
            while (!isEmpty(&stack) && stack.items[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            // Pop the opening parenthesis from the stack
            if (!isEmpty(&stack) && stack.items[stack.top] == ')') {
                pop(&stack);
            }
        }
    }

    // Pop any remaining operators from the stack and add them to the prefix expression
    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
    prefix[j] = '\0';
}

int main() {
    char infix[maxSize], prefix[maxSize];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}