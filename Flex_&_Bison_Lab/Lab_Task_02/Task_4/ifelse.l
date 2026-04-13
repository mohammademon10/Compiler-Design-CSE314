%{
#include "ifelse.tab.h"
#include <stdlib.h>
%}

%%
"if"    return IF;
"else"  return ELSE;
[a-z]   { yylval.id = yytext[0]; return ID; }
[0-9]+  { yylval.num = atoi(yytext); return NUMBER; }
"="    return '=';
";"    return ';';
"("    return '(';
")"    return ')';
[ \t\n] ;
.       return yytext[0];
%%

int yywrap(){ return 1; }
