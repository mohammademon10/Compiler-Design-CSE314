#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    char str[100];
 

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    char *token;
    token = strtok(str, " ");
    printf("first token: %s\n", token);

    char *keywords[] = {"if", "else", "while", "for", "return", "int", "float", "char", };
   

    while (token != NULL){
        int flag=0;
        for(int i=0;i<8;i++){
            if(strcmp(token,keywords[i])==0){
               flag=1;
               break;
            }
        }

        if(flag)
            printf("%s is a keyword\n",token);
           
        else
            printf("%s is unknown\n",token);
           
       
      
        token = strtok(NULL, " ");
        
    }

    return 0;
}

//use function isKeyword() to check if the token is a keyword or not.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
const char *keywords[] = {"if", "else", "while", "for", "return", "int", "float", "char"};

int isKeyword(const char *token) {
    
    for (int i = 0; i < 8; i++) {
        if (strcmp(token, keywords[i]) == 0) { 
            return 1;  
        }
    }

    return 0; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    char *token;
    token = strtok(str, " ");
    while (token != NULL) {
        if (isKeyword(token)==1) {
            printf("%s is a keyword\n", token);
        } 
        else {
            printf("%s is unknown\n", token);
        }

        token = strtok(NULL, " ");
    }

    return 0;
}