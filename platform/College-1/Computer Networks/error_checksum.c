#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate checksum
uint16_t calculate_checksum(uint8_t *data, size_t length) {
    uint32_t sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += data[i];
        if (sum & 0xFFFF0000) {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }
    }
    return ~sum & 0xFFFF;
}

// Function to check for errors in the data stream
int check_data(uint8_t *data, size_t length, uint16_t received_checksum) {
    uint16_t calculated_checksum = calculate_checksum(data, length);
    return calculated_checksum == received_checksum;
}

// Function to convert binary string to byte array
size_t binary_string_to_byte_array(const char *binary_string, uint8_t **data) {
    size_t length = strlen(binary_string);
    *data = (uint8_t *)malloc(length);
    if (*data == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length; i++) {
        if (binary_string[i] == '0') {
            (*data)[i] = 0;
        } else if (binary_string[i] == '1') {
            (*data)[i] = 1;
        } else {
            fprintf(stderr, "Invalid character in binary string: %c\n", binary_string[i]);
            free(*data);
            exit(EXIT_FAILURE);
        }
    }
    return length;
}

int main() {
    // invalid 10102
    char binary_input[256];
    printf("Enter binary string: ");
    scanf("%255s", binary_input);

    uint8_t *data;
    size_t length = binary_string_to_byte_array(binary_input, &data);

    uint16_t checksum = calculate_checksum(data, length);
    printf("Calculated Checksum: 0x%04X\n", checksum);

    // Check data for errors
    int is_valid = check_data(data, length, checksum);
    if (is_valid) {
        printf("Data is valid.\n");
    } else {
        printf("Data is corrupted.\n");
    }

    free(data);
    return 0;
}