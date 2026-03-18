#include <stdio.h>
#include <string.h>

/* 1) a */
int is_a(const char *str) {
    return strcmp(str, "a") == 0;
}

/* 2) a|b */
int is_a_or_b(const char *str) {
    return (strcmp(str, "a") == 0) || (strcmp(str, "b") == 0);
}

/* 3) ab */
int is_ab(const char *str) {
    return strcmp(str, "ab") == 0;
}

/* 4) empty string (epsilon) */
int is_empty_string(const char *str) {
    return str[0] == '\0';
}

/* 5) a*  (includes empty string) */
int is_a_star(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a') return 0;
    }
    return 1;
}

/* 6) a+  (one or more a) */
int is_a_plus(const char *str) {
    if (str[0] == '\0') return 0;   // must have at least one char
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a') return 0;
    }
    return 1;
}

/* 7) a*a+  == a+ */
int is_a_star_a_plus(const char *str) {
    return is_a_plus(str);
}

/* 8) a*b+  (zero or more a, then one or more b) */
int is_a_b_plus(const char *str) {
    int i = 0;

    // consume a*
    while (str[i] == 'a') i++;

    // must have at least one b
    if (str[i] != 'b') return 0;

    // consume b+
    while (str[i] == 'b') i++;

    // must end here
    return str[i] == '\0';
}

/* 9) abb */
int is_abb(const char *str) {
    return strcmp(str, "abb") == 0;
}

/* 10) a*b*  (any number of a then any number of b, includes empty) */
int is_a_b_star(const char *str) {
    int i = 0;

    while (str[i] == 'a') i++;
    while (str[i] == 'b') i++;

    return str[i] == '\0';
}

/* 11) (a|b)+c  : one or more a/b then c at end */
int is_a_b_plus_c(const char *str) {
    int len = (int)strlen(str);
    if (len < 2) return 0;
    if (str[len - 1] != 'c') return 0;

    for (int i = 0; i < len - 1; i++) {
        if (str[i] != 'a' && str[i] != 'b') return 0;
    }
    return 1;
}

/* 12) (a|b)*c  : zero or more a/b then c at end */
int is_a_b_star_c(const char *str) {
    int len = (int)strlen(str);
    if (len < 1) return 0;
    if (str[len - 1] != 'c') return 0;

    for (int i = 0; i < len - 1; i++) {
        if (str[i] != 'a' && str[i] != 'b') return 0;
    }
    return 1;
}

/* 13) (ab)^2+  meaning: (ab)(ab)+  => "abab", "ababab", "abababab", ...  */
int is_ab_ab_plus(const char *str) {
    int len = (int)strlen(str);
    if (len < 4) return 0;
    if (strncmp(str, "abab", 4) != 0) return 0;

    // after "abab", the rest must be (ab)*
    for (int i = 4; i < len; i += 2) {
        if (i + 1 >= len) return 0;
        if (str[i] != 'a' || str[i + 1] != 'b') return 0;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove trailing newline
    str[strcspn(str, "\n")] = '\0';

    int matched = 0;

    if (is_a(str)) { printf("String accepted under a\n"); matched = 1; }
    if (is_a_or_b(str)) { printf("String accepted under a|b\n"); matched = 1; }
    if (is_ab(str)) { printf("String accepted under ab\n"); matched = 1; }
    if (is_empty_string(str)) { printf("String accepted under empty string\n"); matched = 1; }
    if (is_a_star(str)) { printf("String accepted under a*\n"); matched = 1; }
    if (is_a_plus(str)) { printf("String accepted under a+\n"); matched = 1; }
    if (is_a_star_a_plus(str)) { printf("String accepted under a*a+\n"); matched = 1; }
    if (is_a_b_star(str)) { printf("String accepted under a*b*\n"); matched = 1; }
    if (is_a_b_plus(str)) { printf("String accepted under a*b+\n"); matched = 1; }
    if (is_abb(str)) { printf("String accepted under abb\n"); matched = 1; }
    if (is_a_b_plus_c(str)) { printf("String accepted under (a|b)+c\n"); matched = 1; }
    if (is_a_b_star_c(str)) { printf("String accepted under (a|b)*c\n"); matched = 1; }
    if (is_ab_ab_plus(str)) { printf("String accepted under (ab)^2+\n"); matched = 1; }

    if (!matched) {
        printf("String not accepted\n");
    }

    return 0;
}