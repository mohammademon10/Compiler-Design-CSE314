//Q1. This program calculates the length of a string without using built-in functions.


#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }

    printf("Length of the string: %d\n", length);
    return 0;
}

// Sample Input/Output:
// Enter a string: Hello, World!
// Length of the string: 13

//using built-in function strlen for verification
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    int length = strlen(str);
    printf("Length of the string using built-in function: %d\n", length);
    return 0;
}