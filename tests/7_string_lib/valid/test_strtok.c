// Exit code: 0
#include <string.h>

/* Test multiple and consecutive delimiters */
int test_basic() {
    char s[11] = ",,a,,,b,,c";
    char *p = strtok(s, ",");
    if (!p || strcmp(p, "a") != 0) return 1;
    
    p = strtok(NULL, ",");
    if (!p || strcmp(p, "b") != 0) return 1;
    
    p = strtok(NULL, ",");
    if (!p || strcmp(p, "c") != 0) return 1;
    
    if (strtok(NULL, ",") != NULL) return 1;
    return 0;
}

int test_no_delims() {
    char s[4] = "abc";
    char *p = strtok(s, ",");
    return (!p || strcmp(p, "abc") != 0) ? 1 : 0;
}

int test_example_from_standard() {
    char str[12] = "?a???b,,,#c";
    char *t;

    t = strtok(str, "?");
    if(strcmp(t, "a") != 0) return 1;

    t = strtok(NULL, ",");
    if(strcmp(t, "??b") != 0) return 1;

    t = strtok(NULL, "#,");
    if(strcmp(t, "c") != 0) return 1;

    t = strtok(NULL, "?");
    if(t != NULL) return 1;

    return 0;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_no_delims() != 0) return 2;
    if (test_example_from_standard() != 0) return 3;
    return 0;
}
