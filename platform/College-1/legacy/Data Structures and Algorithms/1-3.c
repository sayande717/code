#include<stdio.h>

// First recurse till the last character of the string, till print them one by one.
// *inStr points to the first character of the inputString.
void reverse(char *inStr) {
    if(*inStr) {
        // Exclusively for strings, *VAL points to the value, while VAL points to the address of the value.
        reverse(inStr+1);
        printf("%c",*inStr);
    }
}

int main() {
    char inputString[] = "Sayan De";
    reverse(inputString);
    return 0;
}
