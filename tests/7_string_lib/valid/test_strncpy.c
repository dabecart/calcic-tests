// Exit code: 0
#include <string.h>

/* Test exact size limit */
int test_exact() {
    char d[5] = "xxxx";
    strncpy(d, "abc", 4);
    return (d[0]=='a' && d[1]=='b' && d[2]=='c' && d[3]=='\0' && d[4]=='\0') ? 0 : 1;
}

/* Test truncation: should NOT write null terminator */
int test_no_null() {
    char d[6] = "xxxxx";
    strncpy(d, "abcde", 3);
    return (d[0]=='a' && d[1]=='b' && d[2]=='c' && d[3]=='x') ? 0 : 1;
}

/* Test padding: must pad remaining n bytes with nulls */
int test_padding() {
    char d[6] = "xxxxxx";
    strncpy(d, "ab", 5);
    return (d[0]=='a' && d[1]=='b' && d[2]=='\0' && d[3]=='\0' && d[4]=='\0' && d[5]=='x') ? 0 : 1;
}

int main(void) {
    if (test_exact() != 0) return 1;
    if (test_no_null() != 0) return 2;
    if (test_padding() != 0) return 3;
    return 0;
}
