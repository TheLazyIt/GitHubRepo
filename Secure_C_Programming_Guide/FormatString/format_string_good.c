#include <stdio.h>

int main() {
    char user_input[100];
    scanf("%99s", user_input);
    printf("%s", user_input); // Always use format specifiers
    return 0;
}
