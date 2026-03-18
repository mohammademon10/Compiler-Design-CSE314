/using library function isspace 
#include <stdio.h>
#include <ctype.h>
int main()
 {
    char a;
    scanf("%c", &a);

    if (isspace(a))//isspace function: 0 for false and non zero for true
     {
        printf("Whitespace character\n");
    } else {
        printf("Not a whitespace character\n");
    }

    return 0;
}
