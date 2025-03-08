#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_even(int num) {
    return (num % 2 == 0);
}

int find_length(int num) {
    if (num == 0) {
        return 1; // 0 has one digit
    }
    return (int)log10(num) + 1;
}

// 2^r >= m + r + 1, Start from r=1
int no_parity_bits(int data) {
    int r = 1; // start
    int m = find_length(data);
    do {
        int LHS = (int)pow(2, r);
        int RHS = m + r + 1;
        if (LHS >= RHS) {
            return r;
        }
        r++;
    } while (true);
}

void print_bits(int *data, int len) {
    for (int i = len; i >= 1; i--) {
        printf("%d", data[i]);
    }
    printf("\n");
}

void gen_code(int data, int *buffer, bool *parity, int len) {
    int power = 0;
    int index = 1;
    while (data != 0) {
        if (index == (int)pow(2, power)) {
            parity[index] = true;
            power++;
        } else {
            int digit = data % 10; // Insert data bit.
            buffer[index] = digit;
            data = data / 10;
        }
        index++;
    }
    // At this point, the data bits have been inserted into their positions.
    // Now, we calculate the parity bits.
    // 1. Traverse over the entire buffer array.
    for (int i = 1; i <= len; i++) {
        // 2. If a parity bit is found...
        if (parity[i] == true) {
            int count = 0;
            // 3. Traverse through the rest of the array, and calculate the number of 1's
            for (int j = i; j <= len; j += (i * 2)) {
                for (int k = j; k < j + i && k <= len; k++) {
                    if (parity[k] == false && buffer[k] == 1) {
                        count++;
                    }
                }
            }
            buffer[i] = is_even(count) ? 0 : 1;
        }
    }
}

int main() {
    int data;
    printf("Enter data bits: "); scanf("%d",&data);

    int m = find_length(data);
    int r = no_parity_bits(data);
    int len = m + r;
    int *buffer = (int*)malloc(sizeof(int)*(len+1));
    int *recvd_buffer = (int*)malloc(sizeof(int)*(len+1));
    bool *parity = (bool*)malloc(sizeof(bool)*(len + 1));

    if (buffer == NULL || recvd_buffer==NULL || parity == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= len; i++) {
        buffer[i] = 0;
        parity[i] = false;
    }

    gen_code(data, buffer, parity, len);
    printf("Hamming code: "); print_bits(buffer, len);
    free(buffer);
    free(recvd_buffer);
    free(parity);
    return EXIT_SUCCESS;
}