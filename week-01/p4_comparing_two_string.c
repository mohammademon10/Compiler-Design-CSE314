//Program 4: Comparing Two Strings (Using strcmp()) & without Built-in function.

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

    if (strcmp(str1, str2) == 0)
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");
    return 0;
}


//Alternative Solution:
#include <stdio.h>
#include <string.h>
int main(){

char str1[100], str2[100];

printf("Enter first string: ");
fgets(str1, sizeof(str1), stdin);
str1[strcspn(str1, "\n")] = '\0';

printf("Enter second string: ");
fgets(str2, sizeof(str2), stdin);
str2[strcspn(str2, "\n")] = '\0';

int result = strcmp(str1, str2);

if (result == 0)
    printf("Strings are equal.\n");
else if (result < 0)
     printf("First string is less than second.\n");
else
     printf("First string is greater than second.\n");

     return 0;
}



//Without Built-in Function:
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i = 0;
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) break;
        i++;
    }

    if (str1[i] == str2[i])
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");
    return 0;
}
