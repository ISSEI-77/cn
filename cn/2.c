#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Include this header for uint16_t and uint8_t

#define POLY 0x80F

uint16_t crc_12(uint8_t data[], size_t length) {
    uint16_t crc = 0xFFF;

    for (size_t i = 0; i < length; i++) {
        crc ^= (data[i] << 4);

        for (size_t j = 0; j < 8; j++) {
            if (crc & 0x800) {
                crc = (crc << 1) ^ POLY;
            } else {
                crc <<= 1;
            }
        }
    }
    return crc & 0xFFF;
}

int main() {
    uint8_t data[] = {0x12, 0x34, 0x56};
    size_t length = sizeof(data) / sizeof(data[0]);

    uint16_t result = crc_12(data, length);

    printf("CRC-12 : 0x%03X\n", result); // Added newline for better output formatting
    return 0;
}