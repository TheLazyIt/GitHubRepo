#include <stdio.h>

int main() {
    char name[8];
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s", name);
    return 0;
}
