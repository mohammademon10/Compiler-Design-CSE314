//Program 2: Copying One String to Another (Using strcpy()) & without Built-in function.
#include <stdio.h>
#include <string.h>
int main() {

    char str1[100], str2[100];
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    strcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    return 0;
}


// Without using built-in function
#include <stdio.h>
int main() {
    char str1[100], str2[100];
    int i;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    // Copying string without using built-in function
    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    str2[i] = '\0'; // Null-terminate the copied string

    printf("Copied string without using built-in function: %s\n", str2);
    return 0;
}