%{
#include <stdio.h>
%}

%%
input:
      /* empty */
    | input line
    ;

line:
      '\n'
    | 'a' '\n' { printf("You typed a\n"); }
    ;
%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
}

Input → Flex → Tokens → Bison → Parse → Output