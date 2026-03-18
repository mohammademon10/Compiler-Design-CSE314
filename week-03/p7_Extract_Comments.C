#include <stdio.h>

int main() {
    char code[500];
    printf("Enter code (single line for demo): ");
    fgets(code, sizeof(code), stdin);

    printf("Comments found:\n");

    for(int i=0; code[i]!='\0'; i++) {
        if(code[i]=='/' && code[i+1]=='/') {
            i+=2; // Skip the '//' characters
            while(code[i]!='\0')
                printf("%c", code[i++]);
            printf("\n");
        }
    }
    return 0;
}