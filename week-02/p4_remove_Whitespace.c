/ remove whitespace using a second string

 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
 {
    char str[100], result[100];

    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int j = 0;

   // for (int i = 0; i < strlen(str); i++)
   for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i])) // Check if the character is not a whitespace
        {
            result[j] = str[i];
            j++;
        }  
    }
    
   result[j] = '\0';// Null-terminate the result string

    printf("String without whitespace: %s\n", result);
    return 0;
}


//string remove whitespace in place 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int size;
    printf("Enter the size of string: ");
    scanf("%d", &size);
    getchar(); // to consume the newline character after size input 

    //char str[100];

    char str[size];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int j = 0;

   /* for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) { // Check if the character is not a whitespace
            str[j] = str[i];
            j++;
        }
    }
    */
    for (int i = 0; str[i] != '\0'; i++){
        if(isspace(str[i])){
            continue;
        }
        str[j++] = str[i];
    }    

    str[j] = '\0'; // Null-terminate the modified string//when size input no need to this line

    printf("String without whitespace: %s\n", str);
    return 0;
} 