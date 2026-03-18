//identification whatespace single character
#include <stdio.h>
int main() {
    char a;
    printf("Enter a character: ");
    scanf("%c", &a);

    if (a == ' ' || a == '\t' || a == '\n')
     {
        printf("Whitespace character\n");
    }
     else
      {
        printf("Not a whitespace character\n");
    }
             
    return 0;
}
