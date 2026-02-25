// Exit code: 0
#include <string.h>

/* Test standard copy including null terminator */
int test_basic() {
    char d[10] = "xxxxxxxxx";
    strcpy(d, "abc");
    return (d[0]=='a' && d[1]=='b' && d[2]=='c' && d[3]=='\0' && d[4]=='x') ? 0 : 1;
}

/* Test empty string copy */
int test_empty() {
    char d[10] = "xxxxxxxxx";
    strcpy(d, "");
    return (d[0]=='\0' && d[1]=='x') ? 0 : 1;
}

int main(void) {
    if (test_basic() != 0) return 1;
    if (test_empty() != 0) return 2;
    return 0;
}
