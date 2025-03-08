#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define len 20 // Max length between the stack and the result array.

struct charStack {
    char arr[len];
    int top;
} bufferStack;

char resultArray[len];

void initStack() {
    bufferStack.top = -1;
}

bool isEmpty() {
    return (bufferStack.top == -1);
}

bool isFull() {
    return (bufferStack.top == len - 1);
}

void push(char ch) {
    if (isFull()) {
        printf("Stack Overflow.");
        return;
    }
    bufferStack.arr[++bufferStack.top] = ch;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow.");
        return;
    }
    bufferStack.top--;
}

char peek() {
    if (isEmpty()) {
        return '\0';
    }
    return bufferStack.arr[bufferStack.top];
}

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return -1;
}

void toPostfix(char *exp) {
    int resultIndex = 0;
    int expLen = strlen(exp);

    for (int expIndex = 0; expIndex < expLen; expIndex++) {
        char currentChar = exp[expIndex];

        // Operand
        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= '0' && currentChar <= '9')) {
            resultArray[resultIndex++] = currentChar;
        }

        // Bracket: OPEN
        else if (currentChar == '(') {
            push(currentChar);
        } 

        // Bracket: CLOSE
        else if (currentChar == ')') {
            while (!isEmpty() && peek() != '(') {
                resultArray[resultIndex++] = peek();
                pop();
            }
            // EXCEPTION: Bracket CLOSE without OPEN means expression is invalid.
            if (!isEmpty() && peek() != '(') {
                printf("Expression invalid.");
                return;
            } else {
                pop();
            }
        }

        // Operator
        else {
            while (!isEmpty() && precedence(currentChar) <= precedence(peek())) {
                resultArray[resultIndex++] = peek();
                pop();
            }
            push(currentChar);
        }
    }

    // Take care of the rest of the stack, post evaluation.
    while (!isEmpty()) {
        resultArray[resultIndex++] = peek();
        pop();
    }

    // The null terminator denotes the end of the char[] string.
    resultArray[resultIndex] = '\0'; 
}

int main() {
    initStack(); // Initialize the stack
    char exp[len];

    printf("Enter arithmetic expression (till %d characters): ",len);
    scanf("%s", exp);
    toPostfix(exp);
    printf("\nPostfix: %s\n", resultArray);
    return 0;
}