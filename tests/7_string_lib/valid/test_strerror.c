// Exit code: 0
#include <string.h>
#include <errno.h>

/* Test standard valid output */
int test_valid() {
    char *err = strerror(EDOM);
    return (err != NULL && strlen(err) > 0) ? 0 : 1;
}

int main(void) {
    if (test_valid() != 0) return 1;
    return 0;
}
