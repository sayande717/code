#include<stdio.h>

struct charStack {
    char arr[30];
    int top;
} name;

void init(struct inStack) {
    inStack.top = -1;
}

int main() {
    // variable `name` is created and initialized.
    //struct charStack name;
   
    init(&name);
    // INPUT
    printf("Enter name: ");
    scanf("%29s",name.arr);
    
}
