// Identify Valid Identifier OR Not

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // remove newline

    bool isValid = false;

    // Empty string check - an empty string cannot be a valid identifier
    if (str[0] == '\0') {
        printf("The string is not a valid identifier.\n");
        return 0;
    }

    // 1. First character: must be letter or underscore
    if (isalpha(str[0]) || str[0] == '_') {
        isValid = true;
    } else {
        isValid = false;
    }

    // 2. Remaining characters: letter, digit, or underscore
    if (isValid== true) {  // only check if first char is valid
        for (int i = 1; str[i] != '\0'; i++) {
            if (!(isalnum(str[i]) || str[i] == '_')) {
                isValid = false;
                break;
            }
        }
    }

    if (isValid) {
        printf("The string is a valid identifier.\n");
    } else {
        printf("The string is not a valid identifier.\n");
    }

    return 0;
}