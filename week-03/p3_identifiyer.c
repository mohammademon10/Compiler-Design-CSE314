#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    char str[100];


    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *identifiers[] = {"var1", "var2", "count", "sum", "total"};
    char *token;
    token = strtok(str, " ");

     while (token != NULL){

        int flag_id=0;//false
        for(int l=0;l<5;l++){
            if(strcmp(token,identifiers[l])==0)//0- means both are same
            {
                flag_id=1;
                break;
            }
        }


        if(flag_id){
            printf("The token '%s' is an identifier.\n", token);
        }
        else {
            printf("The token '%s' is not an identifier.\n", token);
        }

        token = strtok(NULL, " ");

        }

        return 0;
    }


//use of isidentifier() library function

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *identifiers[] = {"var1", "var2", "count", "sum", "total"};

int isidentifier(char *token) {

        int flag_id=0;//false
        for(int i=0;i<5;i++){
            if(strcmp(token,identifiers[i])==0)//0- means both are same
            {
                flag_id=1;
                break;
                //return 1; // true
            }
        }
        return flag_id;
        //return 0; // false
}

int main(){
    char str[100];


    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *token;
    token = strtok(str, " ");

        while (token != NULL){
            
        if(isidentifier(token)){
            printf("The token '%s' is an identifier.\n", token);
        }
        else {
            printf("The token '%s' is not an identifier.\n", token);
        }

        token = strtok(NULL, " ");
    }
        return 0;

 }
