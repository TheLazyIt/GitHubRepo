#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() {
    uint8_t a = 200, b = 100;
    if (UINT8_MAX - a < b) {
        printf("Overflow detected!\n");
    } else {
        uint8_t total = a + b;
        printf("Sum: %u\n", total);
    }
    return 0;
}
