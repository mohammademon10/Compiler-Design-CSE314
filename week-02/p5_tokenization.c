//strtok() function example
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
 

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    char *token;
    token = strtok(str, " ");
    //printf("first token: %s\n", token);//print first token

    while (token != NULL)
     {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    } 


    return 0;
}
//all token: keywords, identifiers, operators, special symbols, constants, etc.