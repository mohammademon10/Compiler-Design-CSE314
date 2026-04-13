%{
#include "abc.tab.h"
%}

%%

"int"|"float"|"if"|"else"   { return KEYWORD; }
[0-9]+                      { return NUMBER; }
[a-zA-Z]+                   { return IDENTIFIER; }
[+\-*/]                     { return OPERATOR; }
[ \t\n]+                    { ; /* ignore whitespace */ }

%%

int yywrap() {
    return 1;
}