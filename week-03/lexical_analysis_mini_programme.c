#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "int", "char", "float", "while", "if", "for",
    "return", "double", "else", "do"
};

const char *operators[] = {
    "+", "-", "*", "/", "=", "<", ">", "<=", ">=", "++", "--"
};

const char *specialSymbols[] = {
    "{", "}", "#", "%", "&", "^", "(", ")", ",", "@"
};

bool isKeyword(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return true;
    }
    return false;
}

bool isOperator(char *str) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(str, operators[i]) == 0)
            return true;
    }
    return false;
}

bool isNumber(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i]))
            return false;
    }
    return (strlen(str) > 0);
}

bool isSymbol(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, specialSymbols[i]) == 0)
            return true;
    }
    return false;
}

bool isIdentifier(char *str) {
    if (isalpha((unsigned char)str[0]) || str[0] == '_') {
        for (int i = 1; str[i] != '\0'; i++) {
            if (!isalnum((unsigned char)str[i]) && str[i] != '_')
                return false;
        }
        return true;
    }
    return false;
}

void removeSemicolon(char str[]) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ';')
            str[j++] = str[i];
    }
    str[j] = '\0';
}

int main() {
    printf("========= Lexical Analyzer =========\n");
    printf("Type END to stop the program.\n\n");

    char str[100];

    while (1) {
        printf("Enter a valid statement:\n> ");

        if (fgets(str, sizeof(str), stdin) == NULL)
            break;

        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "END") == 0) {
            printf("\nProgram Terminated.\n");
            break;
        }

        printf("\nOriginal String: %s\n", str);
        removeSemicolon(str);
        printf("After Removing Semicolons: %s\n", str);

        printf("\n------ Lexical Analysis Result ------\n");

        char *token = strtok(str, " ");

        while (token != NULL) {

            if (isKeyword(token))
                printf("Token: %s  -> Keyword\n", token);
            else if (isOperator(token))
                printf("Token: %s  -> Operator\n", token);
            else if (isNumber(token))
                printf("Token: %s  -> Number\n", token);
            else if (isSymbol(token))
                printf("Token: %s  -> Special Symbol\n", token);
            else if (isIdentifier(token))
                printf("Token: %s  -> Identifier\n", token);
            else
                printf("Token: %s  -> Unrecognized Token\n", token);

            token = strtok(NULL, " ");
        }

        printf("------------------------------------\n\n");
    }

    return 0;
}


// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <ctype.h>

// const char *keywords[] = {
//     "int", "char", "float", "while", "if", "for",
//     "return", "double", "else", "do"
// };

// const char *operators[] = {
//     "+", "-", "*", "/", "=", "<", ">", "<=", ">=", "++", "--"
// };

// const char *specialSymbols[] = {
//     "{", "}", "#", "%", "&", "^", "(", ")", ",", "@"
// };

// bool isKeyword(char *str) {
//     for (int i = 0; i < 10; i++) {
//         if (strcmp(str, keywords[i]) == 0)
//             return true;
//     }
//     return false;
// }

// bool isOperator(char *str) {
//     for (int i = 0; i < 11; i++) {
//         if (strcmp(str, operators[i]) == 0)
//             return true;
//     }
//     return false;
// }

// bool isNumber(char *str) {
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (!isdigit((unsigned char)str[i]))
//             return false;
//     }
//     return (strlen(str) > 0);
// }

// bool isSymbol(char *str) {
//     for (int i = 0; i < 10; i++) {
//         if (strcmp(str, specialSymbols[i]) == 0)
//             return true;
//     }
//     return false;
// }

// bool isIdentifier(char *str) {
//     if (isalpha((unsigned char)str[0]) || str[0] == '_') {
//         for (int i = 1; str[i] != '\0'; i++) {
//             if (!isalnum((unsigned char)str[i]) && str[i] != '_')
//                 return false;
//         }
//         return true;
//     }
//     return false;
// }

// void removeSemicolon(char str[]) {
//     int j = 0;
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] != ';')
//             str[j++] = str[i];
//     }
//     str[j] = '\0';
// }

// int main() {
//     printf("========= Lexical Analyzer =========\n");
//     printf("Type END to stop the program.\n\n");

//     char str[100];

//     while (1) {
//         printf("Enter a valid statement:\n> ");

//         if (fgets(str, sizeof(str), stdin) == NULL)
//             break;

//         str[strcspn(str, "\n")] = '\0';

//         if (strcmp(str, "END") == 0) {
//             printf("\nProgram Terminated.\n");
//             break;
//         }

//         printf("\nOriginal String: %s\n", str);
//         removeSemicolon(str);
//         printf("After Removing Semicolons: %s\n", str);

//         printf("\n------ Lexical Analysis Result ------\n");

//         char *token = strtok(str, " \t\n+-*/=<>(){}#%^&,@");

//         while (token != NULL) {
//             printf("Token: %-10s -> ", token);

//             if (isKeyword(token))
//                 printf("Keyword\n");
//             else if (isOperator(token))
//                 printf("Operator\n");
//             else if (isNumber(token))
//                 printf("Number\n");
//             else if (isSymbol(token))
//                 printf("Special Symbol\n");
//             else if (isIdentifier(token))
//                 printf("Identifier\n");
//             else
//                 printf("Unrecognized Token\n");

//             token = strtok(NULL, " \t\n+-*/=<>(){}#%^&,@");
//         }

//         printf("------------------------------------\n\n");
//     }

//     return 0;
// }