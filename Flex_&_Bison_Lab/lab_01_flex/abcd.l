

%{
    
#include<stdio.h>
int count = 0;

%}




%%

"int"|"if"|"float"    { printf("keyword: %s\n", yytext); }
[0-9]                 { printf("Digit : %s\n", yytext); }
[0-9]+                { 
                        printf("Number : %s\n", yytext); 
                        count++; 
                        printf("Count : %d\n", count); 
                      }

[0-9]+\.[0-9]+        { 
                        printf("Float : %s\n", yytext); 
                        count++; 
                        printf("Count : %d\n", count); 
                      }
"String" {printf("Length: %d",yyleng);}

 [a-z]           {char c =yytext[0];
                 if(c=='a'| c=='e' | c== 'i' | c=='o' | c== 'u')
                 printf("Vowel\n");
                 else
                 printf("Consonnent\n");
                 }                     

[a-z|A-Z|_][a-z|A-Z|0-9|_]*  { printf("Identifier: %s\n", yytext); }

[a-z|A-Z]              { printf("Letter: %s\n", yytext); }

"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--"|"+="|"-="|"+"|"-"|"*"|"/"|"="|"<"|">"|"!"|"%"  { printf("Operator: %s\n", yytext); }

\+                     { printf("Plus: %s\n", yytext); }
\*                     { printf("Multiplicaton: %s\n", yytext); }
\t                     { printf("tab: %s\n", yytext); }

[a-z | A-Z]+   {printf("Length  of Sttring: %d",yyleng); }

[{} | () | [\]]  {printf("Parenthesis: %s\n",yylex);}

"end"                  { return 0; }


%%




int main(){
    printf("it is Flex\n");
    yylex();
    return 0;
}



int yywrap()
{
    return 1;
}
