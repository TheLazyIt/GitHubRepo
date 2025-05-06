#include <stdio.h>

int main() {
    char user_input[100];
    scanf("%99s", user_input);
    printf(user_input); // Attacker controls format string
    return 0;
}
