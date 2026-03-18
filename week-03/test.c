
#include<stdio.h>
#include<string.h>
#include<ctype.h>

const char *keywords[]= {"if","else","while","return","int","float","void"};


int iskeyword(const char *str)
{

    for(int i=0; i<7 ; i++)
    {

        if (strcmp(str, keywords[i])==0)
        {

            return 1;
        }
    }
    return 0;
}





int main()
{

    char str[100];
    printf("Enter String: ");

    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = 0;
    char *token = strtok(str, " ");
     while(token != NULL)
     {

         if (iskeyword(token))
         {

            printf("%s it is valid keyword",token) ;
         }
     }

   return 0;

}
