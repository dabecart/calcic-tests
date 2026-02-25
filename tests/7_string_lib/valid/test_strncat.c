// Exit code: 0
#include <string.h>

/* Test normal concatenation limited by n */
int test_truncate() {
    char d[10] = "ab";
    strncat(d, "cdef", 2);
    return (d[2]=='c' && d[3]=='d' && d[4]=='\0') ? 0 : 1;
}

/* Test n larger than src (should stop at src null and add its own null) */
int test_larger_n() {
    char d[10] = "ab";
    strncat(d, "cd", 5);
    return (d[2]=='c' && d[3]=='d' && d[4]=='\0') ? 0 : 1;
}

int main(void) {
    if (test_truncate() != 0) return 1;
    if (test_larger_n() != 0) return 2;
    return 0;
}
