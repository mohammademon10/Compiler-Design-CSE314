%{
#include "list.tab.h"
%}

%%
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
","   return ',';
[ \t\r\n] ;
.      return yytext[0];
%%

int yywrap() { return 1; }