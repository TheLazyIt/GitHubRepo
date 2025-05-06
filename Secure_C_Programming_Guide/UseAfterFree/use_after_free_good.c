#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    ptr = NULL; // Safe practice
    return 0;
}
