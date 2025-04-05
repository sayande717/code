#include <stdio.h>
#include <string.h>

void generateCRC(char *data, char *divisor, char *crc) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);
    char temp[dataLen + divisorLen];
    char remainder[divisorLen];
    
    strcpy(temp, data);
    for (int i = 0; i < divisorLen - 1; i++) {
        temp[dataLen + i] = '0';
    }
    temp[dataLen + divisorLen - 1] = '\0';

    strncpy(remainder, temp, divisorLen);
    remainder[divisorLen] = '\0';

    for (int i = 0; i < dataLen; i++) {
        if (remainder[0] == '1') {
            for (int j = 0; j < divisorLen; j++) {
                remainder[j] = (remainder[j] == divisor[j]) ? '0' : '1';
            }
        }
        memmove(remainder, remainder + 1, divisorLen - 1);
        remainder[divisorLen - 1] = temp[i + divisorLen];
    }

    strncpy(crc, remainder, divisorLen - 1);
    crc[divisorLen - 1] = '\0';
    printf("\nGenerated CRC: %s\n",crc);

    strcat(data, crc);
    printf("New Data: %s\n", data);
}

int checkCRC(char *data, char *divisor) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);
    char temp[dataLen + 1];
    char remainder[divisorLen];
    strcpy(temp, data);


    strncpy(remainder, temp, divisorLen);
    remainder[divisorLen] = '\0';

    for (int i = 0; i < dataLen - divisorLen + 1; i++) {
        if (remainder[0] == '1') {
            for (int j = 0; j < divisorLen; j++) {
                remainder[j] = (remainder[j] == divisor[j]) ? '0' : '1';
            }
        }
        memmove(remainder, remainder + 1, divisorLen - 1);
        remainder[divisorLen - 1] = temp[i + divisorLen];
    }

    for (int i = 0; i < divisorLen - 1; i++) {
        if (remainder[i] != '0') {
            return 0;
        }
    }
    // 1 = Data is correct
    return 1;
}

int main() {
    char data[100], divisor[100], crc[100];

    int choice;
    printf("1. Generate CRC\n");
    printf("2. Check for data corruption using CRC\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter data: "); scanf("%s", data);
            printf("Enter divisor: "); scanf("%s", divisor);
            generateCRC(data, divisor, crc);
            break;

        case 2: {
            char recv_data[10];
            printf("\nEnter received data: "); scanf("%s", recv_data);

            if(checkCRC(recv_data, divisor)==1) {
                printf("Data is correct.\n");
            } else {
                printf("Data is corrupted.\n");
            }
            break;
        }

        case 3:
            return 0;
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}