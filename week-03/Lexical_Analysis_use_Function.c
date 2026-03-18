// Simple Lexical Analyzer in C
// - Extracts comments
// - Extracts string literals
// - Classifies tokens: keyword, identifier, number, operator, special symbol

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1000

const char *keywords[] = {
    "int","float","double","char","if","else","for","while","do","return",
    "void","switch","case","break","continue","default","long","short","unsigned",
    "signed","const","sizeof","struct","union","typedef","enum","static","extern",
    "register","volatile"
};

int num_keywords = 30;

bool isKeyword(char *word) {
    for (int i = 0; i < num_keywords; i++)
        if (strcmp(word, keywords[i]) == 0)
            return true;
    return false;
}

bool isValidIdentifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return false;

    for (int i = 1; str[i] != '\0'; i++)
        if (!isalnum(str[i]) && str[i] != '_')
            return false;

    return true;
}

bool isNumber(char *str) {
    int i = 0;

    if (str[0] == '+' || str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return false;

    return true;
}

bool isOperator(char ch) {
    char operators[] = "+-*/%=<>!&|^";
    for (int i = 0; operators[i] != '\0'; i++)
        if (ch == operators[i])
            return true;
    return false;
}

bool isSpecialSymbol(char ch) {
    char symbols[] = "();,{}[]#.";
    for (int i = 0; symbols[i] != '\0'; i++)
        if (ch == symbols[i])
            return true;
    return false;
}

void extractComments(char *str) {
    int i = 0;
    printf("\nComments found:\n");

    while (str[i] != '\0') {

        // Single-line comment //
        if (str[i] == '/' && str[i + 1] == '/') {
            i += 2;
            while (str[i] != '\0' && str[i] != '\n')
                printf("%c", str[i++]);
            printf("\n");
        }

        // Multi-line comment /* ... */
        else if (str[i] == '/' && str[i + 1] == '*') {
            i += 2;
            while (str[i] != '\0' && !(str[i] == '*' && str[i + 1] == '/'))
                printf("%c", str[i++]);
            if (str[i] != '\0')
                i += 2; // skip */
            printf("\n");
        }

        else {
            i++;
        }
    }
}

void extractStringLiterals(char *str) {
    int i = 0;
    printf("\nString Literals found:\n");

    while (str[i] != '\0') {
        if (str[i] == '"') {
            i++; // skip first "
            while (str[i] != '\0' && str[i] != '"')
                printf("%c", str[i++]);
            if (str[i] == '"')
                i++; // skip closing "
            printf("\n");
        } else {
            i++;
        }
    }
}

int main() {
    char code[MAX];

    printf("Enter C source code (end with EOF / Ctrl+D):\n");

    int c, idx = 0;
    while ((c = getchar()) != EOF && idx < MAX - 1)
        code[idx++] = (char)c;
    code[idx] = '\0';

    // First extract comments and string literals
    extractComments(code);
    extractStringLiterals(code);

    // Now tokenize and classify
    char token[MAX];
    int j = 0;

    printf("\nTokens and their types:\n");

    for (int i = 0; code[i] != '\0'; i++) {

        if (isalnum(code[i]) || code[i] == '_') {
            token[j++] = code[i];
        } else {
            // We hit a delimiter, so end of a word token
            if (j != 0) {
                token[j] = '\0';

                if (isKeyword(token))
                    printf("%s : Keyword\n", token);
                else if (isNumber(token))
                    printf("%s : Number\n", token);
                else if (isValidIdentifier(token))
                    printf("%s : Identifier\n", token);
                else
                    printf("%s : Invalid Identifier\n", token);

                j = 0;
            }

            // Check single character tokens
            if (isOperator(code[i]))
                printf("%c : Operator\n", code[i]);
            else if (isSpecialSymbol(code[i]))
                printf("%c : Special Symbol\n", code[i]);
        }
    }

    // Last token if any
    if (j != 0) {
        token[j] = '\0';
        if (isKeyword(token))
            printf("%s : Keyword\n", token);
        else if (isNumber(token))
            printf("%s : Number\n", token);
        else if (isValidIdentifier(token))
            printf("%s : Identifier\n", token);
        else
            printf("%s : Invalid Identifier\n", token);
    }

    return 0;
}