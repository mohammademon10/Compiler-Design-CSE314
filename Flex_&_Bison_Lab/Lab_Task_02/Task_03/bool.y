%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token AND OR NOT BVAL NUMBER EQ NEQ LT GT
%left OR
%left AND
%right NOT

%%
input:
    input expr '\n' { printf("Result: %s\n", $2 ? "TRUE" : "FALSE"); }
    | expr '\n'     { printf("Result: %s\n", $1 ? "TRUE" : "FALSE"); }
    ;
expr:
    expr AND expr    { $$ = $1 && $3; }
    | expr OR expr   { $$ = $1 || $3; }
    | NOT expr       { $$ = !$2; }
    | NUMBER LT NUMBER  { $$ = $1 < $3; }
    | NUMBER GT NUMBER  { $$ = $1 > $3; }
    | NUMBER EQ NUMBER  { $$ = $1 == $3; }
    | NUMBER NEQ NUMBER { $$ = $1 != $3; }
    | BVAL           { $$ = $1; }
    | '(' expr ')'   { $$ = $2; }
    ;
%%

void yyerror(const char *s)
{ printf("Syntax Error: %s\n", s); }

int main()
 { printf("Enter expression:\n");
  yyparse();
   return 0; }
