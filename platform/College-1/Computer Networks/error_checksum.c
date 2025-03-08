#include <stdio.h>
#include <stdint.h>

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

int main() {
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t length = sizeof(data) / sizeof(data[0]);

    // Calculate checksum
    uint16_t checksum = calculate_checksum(data, length);
    printf("Calculated Checksum: 0x%04X\n", checksum);

    // Check data for errors
    int is_valid = check_data(data, length, checksum);
    if (is_valid) {
        printf("Data is valid.\n");
    } else {
        printf("Data is corrupted.\n");
    }

    return 0;
}