%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
int sym[26];
char last_id;
%}

%union { int num; char id; }
%token IF ELSE
%token <id> ID
%token <num> NUMBER
%type <num> expr stmt
%nonassoc IFX
%nonassoc ELSE

%%
program: program stmt | stmt ;
stmt:
    IF '(' expr ')' stmt %prec IFX
    { if($3){ printf("%c = %d\n", last_id, $5); } }
    | IF '(' expr ')' stmt ELSE stmt
    {
        if($3) printf("%c = %d\n", last_id, $5);
        else   printf("%c = %d\n", last_id, $7);
    }
    | ID '=' NUMBER ';'
    { last_id = $1; sym[$1-'a'] = $3; $$ = $3; }
    ;
expr: NUMBER { $$ = $1; } ;
%%
void yyerror(const char *s)
{ printf("Error: %s\n", s); }
int main()
{ printf("Enter statements:\n");
 yyparse(); 
 return 0; }
