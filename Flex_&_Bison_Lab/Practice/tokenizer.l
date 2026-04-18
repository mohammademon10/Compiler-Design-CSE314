%{
#include <stdio.h>
%}

%%
[0-9]+        { printf("NUMBER: %s\n", yytext); }
[a-zA-Z]+     { printf("WORD: %s\n", yytext); }
[ \t\n]       ;
.             { printf("SYMBOL: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}

int yywrap() 
{ return 1;}