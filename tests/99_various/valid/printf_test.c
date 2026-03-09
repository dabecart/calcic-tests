// Exit code: 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASSERT_SPRINTF(expected, ...) \
    do { \
        char buf[1024]; \
        int ret = sprintf(buf, __VA_ARGS__); \
        if (strcmp(buf, (expected)) != 0 || ret != (int)strlen(expected)) { \
            fprintf(stderr, "FAIL Line %d: Expected '%s' (len %zu), got '%s' (len %d)\n", \
                    __LINE__, (expected), strlen(expected), buf, ret); \
            exit(__LINE__); \
        } \
    } while(0)

#define ASSERT_SNPRINTF(expected_str, expected_ret, size, ...) \
    do { \
        char buf[1024] = {0}; \
        int ret = snprintf((size) == 0 ? NULL : buf, (size), __VA_ARGS__); \
        if (((size) > 0 && strcmp(buf, (expected_str)) != 0) || ret != (expected_ret)) { \
            fprintf(stderr, "FAIL Line %d: Expected '%s' (ret %d), got '%s' (ret %d)\n", \
                    __LINE__, (expected_str), (expected_ret), buf, ret); \
            exit(__LINE__); \
        } \
    } while(0)

int main(void) {
/* ---------------------------------------------------------------------- */
    /* 1. Basic Text and Escape Characters                                    */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("Hello World", "Hello World");
    ASSERT_SPRINTF("100%", "100%%");
    ASSERT_SPRINTF("%", "%%");
    ASSERT_SPRINTF("a%b%c", "a%%b%%c");

    /* ---------------------------------------------------------------------- */
    /* 2. Signed Integers and Flag Combinations                               */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("0", "%d", 0);
    ASSERT_SPRINTF("-42", "%d", -42);
    ASSERT_SPRINTF("+42", "%+d", 42);
    ASSERT_SPRINTF(" 42", "% d", 42);
    
    /* Flag Precedence: '+' overrides ' ' (space) */
    ASSERT_SPRINTF("+42", "%+ d", 42);
    ASSERT_SPRINTF("+42", "% +d", 42);
    
    /* Flag Precedence: '-' overrides '0' */
    ASSERT_SPRINTF("42   ", "%-05d", 42);
    ASSERT_SPRINTF("42   ", "%0-5d", 42);

    /* ---------------------------------------------------------------------- */
    /* 3. Unsigned Integers, Hex/Octal, and Alternate Form (#)                */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("255", "%u", 255u);
    ASSERT_SPRINTF("377", "%o", 255u);
    ASSERT_SPRINTF("0377", "%#o", 255u);
    ASSERT_SPRINTF("ff", "%x", 255u);
    ASSERT_SPRINTF("0xff", "%#x", 255u);
    ASSERT_SPRINTF("FF", "%X", 255u);
    
    /* Alternate form padding behavior */
    ASSERT_SPRINTF("0x0000ff", "%#08x", 255u);
    ASSERT_SPRINTF("  0x00ff", "%#8.4x", 255u); /* 0 flag ignored if precision given */
    
    /* Edge cases for 0 with alternate form */
    ASSERT_SPRINTF("0", "%#x", 0u); 
    ASSERT_SPRINTF("0", "%#X", 0u);
    ASSERT_SPRINTF("0", "%#o", 0u);

    /* ---------------------------------------------------------------------- */
    /* 4. Width and Padding                                                   */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("   42", "%5d", 42);
    ASSERT_SPRINTF("42   ", "%-5d", 42);
    ASSERT_SPRINTF("00042", "%05d", 42);
    ASSERT_SPRINTF("+0042", "%+05d", 42);
    ASSERT_SPRINTF("-0042", "%05d", -42);
    
    /* Extreme width test */
    ASSERT_SPRINTF("                                      42", "%40d", 42);

    /* ---------------------------------------------------------------------- */
    /* 5. Precision Edge Cases                                                */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("042", "%.3d", 42);
    ASSERT_SPRINTF("  042", "%5.3d", 42);
    
    /* Precision with zero value */
    ASSERT_SPRINTF("", "%.0d", 0);
    ASSERT_SPRINTF("", "%.0x", 0u);
    ASSERT_SPRINTF("", "%.0u", 0u);
    ASSERT_SPRINTF("0", "%#.0o", 0u); /* # forces at least one '0' for octal */
    ASSERT_SPRINTF("  ", "%2.0d", 0); /* Width maintained even if value is empty */

    /* ---------------------------------------------------------------------- */
    /* 6. Dynamic Width and Precision (*) Conflicts                           */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("   42", "%*d", 5, 42);
    ASSERT_SPRINTF("42   ", "%*d", -5, 42); /* Negative width acts as '-' flag */
    ASSERT_SPRINTF("00042", "%.*d", 5, 42);
    
    /* Negative precision is ignored (treated as if omitted) */
    ASSERT_SPRINTF("42", "%.*d", -5, 42);
    ASSERT_SPRINTF("   42", "%5.*d", -3, 42);

    /* ---------------------------------------------------------------------- */
    /* 7. Strings (%s), Characters (%c), and Empty Strings                    */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("A", "%c", 'A');
    ASSERT_SPRINTF("A", "%-1c", 'A');
    ASSERT_SPRINTF("test", "%s", "test");
    ASSERT_SPRINTF("tes", "%.3s", "test");
    ASSERT_SPRINTF("  tes", "%5.3s", "test");
    ASSERT_SPRINTF("tes  ", "%-5.3s", "test");
    
    /* Empty string handling */
    ASSERT_SPRINTF("", "%s", "");
    ASSERT_SPRINTF("   ", "%3s", "");
    ASSERT_SPRINTF("   ", "%-3s", "");

    /* ---------------------------------------------------------------------- */
    /* 8. Pointers (%p) and Bytes Written (%n)                                */
    /* ---------------------------------------------------------------------- */
    /* Pointer format is implementation-defined. This tests basic processing. */
    char buf_ptr[128];
    void *ptr = (void *)0xdeadbeef;
    int ret_ptr = sprintf(buf_ptr, "%p", ptr);
    if (ret_ptr <= 0) {
        fprintf(stderr, "FAIL Line %d: %%p failed to format.\n", __LINE__);
        exit(__LINE__);
    }

    /* %n feature test */
    int bytes_written = 0;
    ASSERT_SPRINTF("123456", "123%n456", &bytes_written);
    if (bytes_written != 3) {
        fprintf(stderr, "FAIL Line %d: %%n expected 3, got %d\n", __LINE__, bytes_written);
        exit(__LINE__);
    }

    /* ---------------------------------------------------------------------- */
    /* 9. Floating Point Combinations (%f, %e, %g)                            */
    /* ---------------------------------------------------------------------- */
    ASSERT_SPRINTF("3.14", "%.2f", 3.14159);
    ASSERT_SPRINTF("+3.14", "%+.2f", 3.14159);
    ASSERT_SPRINTF(" 3.14", "% .2f", 3.14159);
    ASSERT_SPRINTF("0.000000", "%f", 0.0);
    
    /* # flag forces decimal point even with 0 precision */
    ASSERT_SPRINTF("3.", "%#.0f", 3.14159);
    ASSERT_SPRINTF("3", "%.0f", 3.14159);

    /* ---------------------------------------------------------------------- */
    /* 10. snprintf Truncation & Return Value Standard Compliance             */
    /* ---------------------------------------------------------------------- */
    ASSERT_SNPRINTF("12345", 5, 6, "%s", "12345");
    ASSERT_SNPRINTF("123", 5, 4, "%s", "12345");
    ASSERT_SNPRINTF("", 5, 1, "%s", "12345");
    ASSERT_SNPRINTF("", 5, 0, "%s", "12345");

    /* Truncation in the middle of padding */
    ASSERT_SNPRINTF("   ", 5, 4, "%5d", 42); /* Expects "   42", truncated to 3 spaces + \0 */
    
    /* Truncation during a numeric conversion */
    ASSERT_SNPRINTF("-12", 4, 4, "%d", -123);
    
    /* snprintf with %n (should write number of chars written *so far*, ignoring truncation limit) */
    int sn_written = 0;
    char sn_buf[4];
    snprintf(sn_buf, 4, "12345%n678", &sn_written);
    if (sn_written != 5) {
        fprintf(stderr, "FAIL Line %d: snprintf %%n expected 5, got %d\n", __LINE__, sn_written);
        exit(__LINE__);
    }

    printf("All format tests passed successfully.\n");
    return 0;
}