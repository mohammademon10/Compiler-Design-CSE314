/*
In compiler design, Regular Expressions are used in the Lexical Analysis phase
to define tokens such as:
● Keywords
● Identifiers
● Numbers
● Operators
● Punctuation symbols
The Lexical Analyzer (Lexer or Scanner) uses REs to identify and group characters
into tokens.

*/
//identyf  any keword token
//keywords: if, else, while, return, int, float, void
//operators: +, -, *, /, =, ==, !=, <, >, <=, >=
//punctuation symbols: ;, ,, ., (), {}, []
//identifiers: start with a letter or underscore, followed by letters, digits, or underscores
//numbers: integer and floating-point numbers
//ctype.h library is used for character handling functions like isalpha, isdigit, etc.

#include <stdio.h>// for input/output functions
//#include <stdbool.h>// for boolean data type
#include <string.h>// for string handling functions like strcmp, strtok, etc.
//#include <ctype.h>// for character handling functions like isalpha, isdigit, etc.

const char *keywords[] = {"if", "else", "while", "return", "int", "float", "void"};
const char *operators[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="};
const char *symbols[] = {";", ",", ".", "()", "{}", "[]"};
const char *numbers[] = {"0","1","2","3","4","5","6","7","8","9"};
const char *identifiers[] = {"var1", "var2", "count", "sum", "total"};

int isKeyword(const char *str) {//const 
    for (int i = 0; i < 7 ; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(const char *str) {
    for (int i = 0; i < 10 ; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int issymbols(const char *str) {
    for (int i = 0; i < 6 ; i++) {
        if (strcmp(str, symbols[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isNumber(const char *str) {
    for (int i = 0; i < 10 ; i++) {
        if (strcmp(str, numbers[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(const char *str) {
    for (int i = 0; i < 5 ; i++) {
        if (strcmp(str, identifiers[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main (){

    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

//strtok() splits the input string str by spaces.
//First call → returns pointer to the first token.

char *token = strtok(str," ");

while (token != NULL){

    if (isKeyword(token)) 
        printf("'%s' is a keyword token.\n", token);
    else if (isOperator(token)) 
        printf("'%s' is an operator token.\n", token);
    else if (issymbols(token)) 
        printf("'%s' is a symbol token.\n", token);
    else if (isNumber(token))
        printf("'%s' is a number token.\n", token);
    else if (isIdentifier(token))
        printf("'%s' is an identifier token.\n", token);
     else 
        printf("'%s' is not a recognized token.\n", token);
    
    token = strtok(NULL, " ");//move to the next token
  }

 return 0;
}



