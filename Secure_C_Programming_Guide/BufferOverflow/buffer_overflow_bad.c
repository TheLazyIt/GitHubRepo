#include <stdio.h>

int main() {
    char name[8];
    gets(name); // BOOM. Never use gets()
    printf("Hello, %s\n", name);
    return 0;
}
