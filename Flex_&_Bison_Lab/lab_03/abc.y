%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%token IDENTIFIER KEYWORD NUMBER OPERATOR

%%

input:
    input token
    | token
    ;

token:
    IDENTIFIER { printf("identifier\n"); }
    | KEYWORD    { printf("keyword\n");    }
    | NUMBER     { printf("number\n");     }
    | OPERATOR   { printf("operator\n");   }
    ;

%%

int main() {
    printf("it is parser\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "error: %s\n", s);
}