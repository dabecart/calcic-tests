// Exit code: 0
#include <string.h>

/* Test difference after n bytes (should be ignored) */
int test_diff_after_n() { return strncmp("abcd", "abce", 3) == 0 ? 0 : 1; }

/* Test difference within n bytes */
int test_diff_within_n() { return strncmp("abcd", "abce", 4) < 0 ? 0 : 1; }

/* Test smaller string reaching null byte before n */
int test_early_null() { return strncmp("ab", "abc", 5) < 0 ? 0 : 1; }

int main(void) {
    if (test_diff_after_n() != 0) return 1;
    if (test_diff_within_n() != 0) return 2;
    if (test_early_null() != 0) return 3;
    return 0;
}
