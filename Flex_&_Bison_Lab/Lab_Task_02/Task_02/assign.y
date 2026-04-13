%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
int sym[26];
%}

%token ID NUMBER

%%
program: program stmt | stmt ;
stmt:
    ID '=' expr ';'
    { sym[$1] = $3; printf("%c = %d\n", $1 + 'a', $3); }
    ;
expr:
    expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | NUMBER
    | ID { $$ = sym[$1]; }
    ;
%%

void yyerror(const char *s)
{ printf("Error: %s\n", s); }

int main() 
{ printf("Enter assignments:\n");
 yyparse();
 return 0; }
