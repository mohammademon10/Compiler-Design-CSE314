//program1: Identify integer from string

//code without using library function
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char str[100];
 

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

bool flag = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
    
          flag = 1;
        } else {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("The string represents an integer.\n");
    } else {
        printf("The string does not represent an integer.\n");
    }
return 0;
  
}

//code use isdigit()  Library function 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[100];
 

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    bool flag = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
          flag = 1;
        } else {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("The string represents an integer.\n");
    } else {
        printf("The string does not represent an integer.\n");
    }

  
}