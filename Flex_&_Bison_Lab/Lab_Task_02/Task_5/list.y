%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);

int count = 0;
int arr[100];
%}

%token NUMBER

%%
input:
      list end
      ;

end:
      /* empty */
    ;

list:
      list ',' NUMBER
      {
          arr[count++] = $3;
          printf("Parsed: %d\n", $3);
      }
    | NUMBER
      {
          arr[count++] = $1;
          printf("Parsed: %d\n", $1);
      }
    ;
%%

void yyerror(const char *s){
    printf("Error: %s\n", s);
}

int main(){
    yyparse();
    printf("Total elements: %d\n", count);
    return 0;
}