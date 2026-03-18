#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>//ct
int main(){
 
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';


    char *token;
    token = strtok(str, " ");

    char *operators[] = {"+", "-", "*", "/", "=", "==", "!=","<", ">", "<=", ">="};

    while (token != NULL)
     {
         int flag_op=0;
        for(int j=0;j<9;j++){
            if(strcmp(token,operators[j])==0){
                flag_op=1;
                break;
            }
        }

        if(flag_op){
            printf("The token '%s' is an operator.\n", token);
        }
        else {
            printf("The token '%s' is not an operator.\n", token);
        }

        token = strtok(NULL, " ");

        }

        return 0;
    }

