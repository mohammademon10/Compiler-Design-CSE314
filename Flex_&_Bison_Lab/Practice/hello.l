%{
    #include <stdio.h>
%}

%%
"hello"  {printf("hello found!\n");}
"world" {printf("world found!\n");}
%%

int main()
{
   
    yylex();
    return 0;
}

int yywrap() 
{ return 1;} 
