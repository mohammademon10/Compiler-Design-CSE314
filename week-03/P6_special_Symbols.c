#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const char *special_symbols[] = {"{", "}", "#", "%", "&", "^", "(", ")", ",", "@"};

int main(){

    char str[100];
    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *token = strtok(str, " ");
    
    while (token != NULL)
     {
        bool flag_sym = false;

        for(int m=0;m<10;m++){
            if(strcmp(token,special_symbols[m])==0){
                flag_sym = true;
                break;
            }
        }

        if(flag_sym){
            printf("The token '%s' is a special symbol.\n", token);
        }
        else {
            printf("The token '%s' is not a special symbol.\n", token);
        }

        token = strtok(NULL, " ");

        }

        return 0;
}

