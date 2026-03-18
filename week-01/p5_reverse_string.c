//Q5. Reverse a string without using library functions & without using a second string.

//Using 2 strings and string length given by user
#include <stdio.h>
#include <string.h>

int main() {

    int len;
    printf("Enter the max length of the string: ");
    scanf("%d", &len); 
    getchar(); // clear newline

    char str1[len + 1];  
    char str2[len + 1];

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin); 
    str1[strcspn(str1, "\n")] = '\0';

    int actual_len = strlen(str1); 

    int j = 0;
    for (int i = actual_len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }

    str2[j] = '\0';

    printf("Reversed string: %s\n", str2);
    return 0;
}

//string length given 
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, j, len;

    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    len = strlen(str1);

    j = 0;
    for (i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }
    str2[j] = '\0';

    printf("Reversed string: %s\n", str2);

    return 0;
}

//Without using a second string
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
  
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

     int len = strlen(str);
    
    // Remove newline character if present
    /*
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }*/
    
    str[strcspn(str, "\n")] = '\0';

    
    // Reverse the string in place
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    
    printf("Reversed string: %s\n", str);
    
    return 0;
}


