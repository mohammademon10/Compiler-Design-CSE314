%{
#include "calc.tab.h"
%}

%%
[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"+"     return '+';
"\n"    return '\n';
[ \t]   ;
%%

int yywrap() 
{ return 1;}