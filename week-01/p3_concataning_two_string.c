//Program 3: Concatenating Two Strings (Using strcat()) & without Built-in function.
#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}

// Without using built-in function
#include <stdio.h>
int main() {
    char str1[100], str2[100];
    int i, j;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Find the end of the first string
    for (i = 0; str1[i] != '\0'; i++);

    // Append the second string to the first string
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i] = str2[j];
        i++;
    }
    str1[i] = '\0'; // Null-terminate the concatenated string

    printf("Concatenated string without using built-in function: %s\n", str1);
    return 0;
}

// Without using built-in function (Alternative Method)
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, j;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Check buffer overflow
    if (strlen(str1) + strlen(str2) >= sizeof(str1)) {
        printf("Error: Concatenation exceeds buffer size.\n");
        return 1;
    }

    // Move i to the end of str1
    i = strlen(str1);

    // Append str2 to str1
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i] = str2[j];
        i++;
    }

    
    // Null terminate the final string
    str1[i] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}

