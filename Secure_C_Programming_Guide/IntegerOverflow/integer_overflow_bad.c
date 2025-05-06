#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t a = 200, b = 100;
    uint8_t total = a + b; // if a + b > 255, wraparound
    printf("Sum: %u\n", total);
    return 0;
}
