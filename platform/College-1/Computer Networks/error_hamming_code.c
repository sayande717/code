#include <stdio.h>
#include <math.h>
#include <string.h>

void checkHammingCode(int data[], int n) {
    int parityCount = 0, i, j, parityPos, errorPos = 0;

    // Calculate number of parity bits
    while ((1 << parityCount) < (n + parityCount + 1)) {
        parityCount++;
    }

    // Check parity bits
    for (i = 0; i < parityCount; i++) {
        parityPos = (1 << i);
        int parity = 0;

        for (j = 1; j <= n; j++) {
            if (j & parityPos) {
                parity ^= data[j - 1];
            }
        }

        if (parity != 0) {
            errorPos += parityPos;
        }
    }

    if (errorPos == 0) {
        printf("No error detected in the data stream.\n");
    } else {
        printf("Error detected at position: %d\n", errorPos);
        printf("Corrected data stream: ");
        data[errorPos - 1] ^= 1; // Correct the error
        for (i = 0; i < n; i++) {
            printf("%d", data[i]);
        }
        printf("\n");
    }
}

int main() {
    char input[20];
    int data[20], n, i;

    printf("Enter data: ");
    scanf("%s", input);

    n = strlen(input);
    for (i = 0; i < n; i++) {
        data[i] = input[i] - '0';
    }

    checkHammingCode(data, n);

    return 0;
}