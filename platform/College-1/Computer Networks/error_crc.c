#include <stdio.h>
#include <string.h>
#define POLYNOMIAL 0xD8  // Example polynomial: x^8 + x^7 + x^6 + x^4 + x^2 + 1

void generateCRC(char *input, char *output) {
    int len = strlen(input);
    strcpy(output, input);

    for (int i = 0; i < 8; i++) {
        output[len + i] = '0';
    }
    output[len + 8] = '\0';

    for (int i = 0; i < len; i++) {
        if (output[i] == '1') {
            for (int j = 0; j < 8; j++) {
                output[i + j] = (output[i + j] == POLYNOMIAL & (1 << (7 - j)) ? '1' : '0');
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        output[len + i] = output[len + i] == '1' ? '1' : '0';
    }
}

int detectError(char *input) {
    int len = strlen(input);

    for (int i = 0; i < len - 8; i++) {
        if (input[i] == '1') {
            for (int j = 0; j < 8; j++) {
                input[i + j] = (input[i + j] == POLYNOMIAL & (1 << (7 - j)) ? '1' : '0');
            }
        }
    }

    for (int i = len - 8; i < len; i++) {
        if (input[i] == '1') {
            return 1;  // Error detected
        }
    }

    return 0;  // No error
}

int main() {
    char data[100], encodedData[108];

    printf("Enter data: ");
    scanf("%s", data);

    generateCRC(data, encodedData);
    printf("Encoded data: %s\n", encodedData);

    if (detectError(encodedData)) {
        printf("Error detected in received data.\n");
    } else {
        printf("No error detected in received data.\n");
    }
    return 0;
}