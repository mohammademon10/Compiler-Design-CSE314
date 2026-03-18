#include<stdio.h>
#include<string.h>

//1. (a|b)*
//Accept any combination (including none) of 'a' and 'b'

int is_a_or_b_star( char *str) {
    for (int i = 0; i < strlen(str) ; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return 0;
        }
    }
    return 1;
}

//2. ab*
//Accept strings that start with 'a' followed by zero or more 'b's

int is_a_b_star( char *str) {
    if (strlen(str) == 0) {
        return 0;
    }
    if (str[0] != 'a') {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] != 'b') {
            return 0;
        }
    }
    return 1;
}

//3. a+
//Accept strings with one or more 'a's.

int is_a_plus( char *str) {
    int count = 0;
    for (int i = 0; i<strlen(str) ; i++) {
        if (str[i] == 'a') {
            count++;
        }
        else {
            return 0;
        }
    }
    if (count > 0) {
        return 1;
    }


return 0;
}


//4. (ab|ba)
//Accept exactly either 'ab' or 'ba'
int is_ab_or_ba( char *str) {
    if (strlen(str) == 2 && str[0] == 'a' && str[1] == 'b') {
        return 1;
    }
    if (strlen(str) == 2 && str[0] == 'b' && str[1] == 'a') {
        return 1;
    }
    return 0;
}

//5. (ab)+
//Accept one or more repetitions of 'ab'

int is_ab_plus( char *str) {
    int len = strlen(str);
    if (len < 2 || len % 2 != 0) {
        return 0;
    }
    for(int i = 0; i < len; i += 2) {
        if(str[i] != 'a' || str[i + 1] != 'b') {
            return 0;
        }
    }
    // for (int i = 0; i < len; i += 2) {
    //     if (strcmp(str + i, "ab") != 0) {
    //         return 0;
    //     }
    // }
    return 1;
}


//6.a(bc)+
//Accept 'a' followed by one or more repetitions of 'bc'

int is_a_bc_plus( char *str) {
    int len = strlen(str);
    if (len < 3 || str[0] != 'a' || len % 2 == 0) {
        return 0;
    }
    for (int i = 1; i < len; i += 2) {
        if (str[i] != 'b' || str[i + 1] != 'c') {
            return 0;
        }

    }
    return 1;   
}


// 8. (a|b) c+ d

// Meaning:
// Starts with 'a' or 'b'
// Followed by one or more 'c's
// Ends with exactly one 'd'.

int is_a_or_b_c_plus_d( char *str) {

    int len = strlen(str);
    if (len < 3 || (str[0] != 'a' && str[0] != 'b') || str[len - 1] != 'd') {
        return 0;
    }
    for (int i = 1; i < len - 1; i++) {
        if (str[i] != 'c') {
            return 0;
        }
    }
    return 1;
}

// 9. (ab|ba)(ab)+

// Meaning:
// Starts with 'ab' or 'ba'
// Followed by one or more 'ab'
//strncmp() compares the first n characters of two strings. It returns 0 if they are equal, a negative value if the first string is less than the second, and a positive value if the first string is greater than the second.
int is_ab_or_ba_ab_plus( char *str) {
    int len = strlen(str);
    if (len < 4 || ((strncmp(str, "ab", 2) != 0 && strncmp(str, "ba", 2) != 0)) || len % 2 != 0) {
        return 0;
    }
    for (int i = 2; i < len; i += 2) {
       if(str[i] != 'a' || str[i + 1] != 'b') {
            return 0;
        }
    }
    return 1;   
}

//10. (a|b)*abb

// Meaning:
// Any sequence of 'a' and 'b' ending in 'abb'.
int is_a_or_b_star_abb( char *str) {
    int len = strlen(str);
    if (len < 3 || str[len - 3] != 'a' || str[len - 2] != 'b' || str[len - 1] != 'b') {
        return 0;
    }
    for (int i = 0; i < len - 3; i++) {
        if (str[i] != 'a' && str[i] != 'b') {
            return 0;
        }
    }
    return 1;
}

//11. a(bc|cd)+

// Meaning:
// Starts with 'a'
// Followed by one or more of 'bc' or 'cd'.
int is_a_bc_or_cd_plus( char *str) {
    int len = strlen(str);
    if (len < 3 || str[0] != 'a' || len % 2 == 0) {
        return 0;
    }
    for (int i = 1; i < len; i += 2) {
        if (!((str[i] == 'b' && str[i + 1] == 'c') || (str[i] == 'c' && str[i + 1] == 'd'))) {
            return 0;
        }
    }
    return 1;   
}


//0(1|0)*
//Accept '0' followed by any combination of '0's and '1's

int is_0_1_star( char *str) {
    if (strlen(str) == 0 || str[0] != '0') {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// 12. (01|10)+

// Meaning:
// The string must be one or more repetitions of either 01 or 10.
int is_01_or_10_plus( char *str) {
    int len = strlen(str);
    if (len < 2 || len % 2 != 0) {
        return 0;
    }
    for (int i = 0; i < len; i += 2) {
        if (!((str[i] == '0' && str[i + 1] == '1') || (str[i] == '1' && str[i + 1] == '0'))) {
            return 0;
        }
    }
    return 1;
}


int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

        if (is_a_or_b_star(str)) {
            printf("The string matches the regular expression (a|b)*\n");
        } else if (is_a_b_star(str)) {
            printf("The string matches the regular expression ab*\n");
        } else if (is_a_plus(str)) {
            printf("The string matches the regular expression a+\n");
        } else if (is_ab_or_ba(str)) {
            printf("The string matches the regular expression (ab|ba)\n");
        } else if (is_ab_plus(str)) {
            printf("The string matches the regular expression (ab)+\n");
        } else if (is_a_bc_plus(str)) {
            printf("The string matches the regular expression a(bc)+\n");
        } else if (is_a_or_b_c_plus_d(str)) {
            printf("The string matches the regular expression (a|b) c+ d\n");
        } else if (is_ab_or_ba_ab_plus(str)) {
            printf("The string matches the regular expression (ab|ba)(ab)+\n");
        } else if (is_a_or_b_star_abb(str)) {
            printf("The string matches the regular expression (a|b)*abb\n");
        } else if (is_a_bc_or_cd_plus(str)) {
            printf("The string matches the regular expression a(bc|cd)+\n"); 
        } else if (is_0_1_star(str)) {
            printf("The string matches the regular expression 0(1|0)*\n");
        } else if (is_01_or_10_plus(str)) {
            printf("The string matches the regular expression (01|10)+\n");
        } else {
            printf("The string does not match any of the specified regular expressions.\n");
        }

    return 0;
}