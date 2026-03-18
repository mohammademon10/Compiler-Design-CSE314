//count whitespace an input string

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int count = 0;
     
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < strlen (str); i++) {
        if (isspace(str[i]))
           count++;
    }
    printf ("Number of whitespace characters: %d\n", count);
    return 0;
}
