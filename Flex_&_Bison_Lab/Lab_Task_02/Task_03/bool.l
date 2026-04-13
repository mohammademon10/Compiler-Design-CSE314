%{
#include "bool.tab.h"
%}
%%
"AND"   return AND;
"OR"    return OR;
"NOT"   return NOT;
"TRUE"  { yylval = 1; return BVAL; }
"FALSE" { yylval = 0; return BVAL; }
[0-9]+  { yylval = atoi(yytext); return NUMBER; }
"=="   return EQ;
"!="   return NEQ;
"<"    return LT;
">"    return GT;
"("    return '(';
")"    return ')';
\n      return '\n';
[ \t]  ;
.       { return yytext[0]; }
%%
int yywrap(){ return 1; }
