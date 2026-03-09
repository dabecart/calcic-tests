// Exit code: 0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>

/* * Macro to evaluate a condition. If it evaluates to false, the program 
 * immediately returns the line number of the failure (a non-zero integer).
 */
#define ASSERT_TEST(cond) do { if (!(cond)) return __LINE__; } while(0)

int main(void) {
    char *endptr;
    long l_val;
    unsigned long ul_val;
    float f_val;
    double d_val;
    
    // long long ll_val;
    // unsigned long long ull_val;
    // long double ld_val;

    /* --- strtol --- */
    /* Base 10 normal conversion */
    errno = 0;
    l_val = strtol("12345", &endptr, 10);
    ASSERT_TEST(l_val == 12345 && *endptr == '\0' && errno == 0);

    /* Base 16 with negative sign */
    errno = 0;
    l_val = strtol("-0x1A", &endptr, 16);
    ASSERT_TEST(l_val == -26 && *endptr == '\0' && errno == 0);

    /* Base 0 auto-detect (octal) */
    errno = 0;
    l_val = strtol("010", &endptr, 0); 
    ASSERT_TEST(l_val == 8 && *endptr == '\0' && errno == 0);

    /* Leading whitespace and trailing non-numeric characters */
    errno = 0;
    l_val = strtol("  42abc", &endptr, 10);
    ASSERT_TEST(l_val == 42 && *endptr == 'a' && errno == 0);

    /* Overflow */
    errno = 0;
    l_val = strtol("999999999999999999999999999999", &endptr, 10);
    ASSERT_TEST(l_val == LONG_MAX && errno == ERANGE);

    // /* --- strtoll --- */
    // /* Normal base 10 conversion */
    // errno = 0;
    // ll_val = strtoll("9223372036854775807", &endptr, 10);
    // ASSERT_TEST(ll_val == 9223372036854775807LL && *endptr == '\0' && errno == 0);

    // /* Underflow */
    // errno = 0;
    // ll_val = strtoll("-999999999999999999999999999999", &endptr, 10);
    // ASSERT_TEST(ll_val == LLONG_MIN && errno == ERANGE);

    /* --- strtoul --- */
    /* Normal base 16 conversion */
    errno = 0;
    ul_val = strtoul("0xFFFFFFFF", &endptr, 16);
    ASSERT_TEST(ul_val == 4294967295UL && *endptr == '\0' && errno == 0);

    /* Overflow */
    errno = 0;
    ul_val = strtoul("999999999999999999999999999999", &endptr, 10);
    ASSERT_TEST(ul_val == ULONG_MAX && errno == ERANGE);

    // /* --- strtoull --- */
    // /* Normal base 10 conversion */
    // errno = 0;
    // ull_val = strtoull("18446744073709551615", &endptr, 10);
    // ASSERT_TEST(ull_val == 18446744073709551615ULL && *endptr == '\0' && errno == 0);

    // /* Overflow */
    // errno = 0;
    // ull_val = strtoull("999999999999999999999999999999999", &endptr, 10);
    // ASSERT_TEST(ull_val == ULLONG_MAX && errno == ERANGE);

    /* --- strtof --- */
    /* Normal float conversion */
    errno = 0;
    f_val = strtof("3.14159", &endptr);
    ASSERT_TEST(f_val > 3.14158f && f_val < 3.14160f && *endptr == '\0' && errno == 0);

    /* C99 Hexadecimal float (1 + 5/16) * 2^2 = 1.3125 * 4 = 5.25 */
    errno = 0;
    f_val = strtof("0x1.5p2", &endptr); 
    ASSERT_TEST(f_val == 5.25f && *endptr == '\0' && errno == 0);

    /* C99 NaN parsing */
    errno = 0;
    f_val = strtof("NAN", &endptr);
    ASSERT_TEST(isnan(f_val) && *endptr == '\0' && errno == 0);

    /* C99 Infinity parsing */
    errno = 0;
    f_val = strtof("INF", &endptr);
    ASSERT_TEST(isinf(f_val) && *endptr == '\0' && errno == 0);

    /* Out of range (Overflow) */
    errno = 0;
    f_val = strtof("1e39", &endptr);
    ASSERT_TEST(f_val == HUGE_VALF && errno == ERANGE);

    /* --- strtod --- */
    /* Normal double conversion */
    errno = 0;
    d_val = strtod("2.718281828", &endptr);
    ASSERT_TEST(d_val > 2.71828 && d_val < 2.71829 && *endptr == '\0' && errno == 0);

    /* C99 Hexadecimal double with negative sign */
    /* -(1 + 15/16) * 2^3 = -(31/16) * 8 = -15.5 */
    errno = 0;
    d_val = strtod("-0x1.fp3", &endptr); 
    ASSERT_TEST(d_val == -15.5 && *endptr == '\0' && errno == 0);

    /* Overflow */
    errno = 0;
    d_val = strtod("1e310", &endptr); 
    ASSERT_TEST(d_val == HUGE_VAL && errno == ERANGE);

    /* Underflow */
    errno = 0;
    d_val = strtod("1e-350", &endptr); 
    ASSERT_TEST(d_val == 0.0);

    // /* --- strtold --- */
    // /* Normal long double conversion */
    // errno = 0;
    // ld_val = strtold("1.4142135623730950488", &endptr);
    // ASSERT_TEST(ld_val > 1.414 && ld_val < 1.415 && *endptr == '\0' && errno == 0);

    /* --- ato* series --- */
    /* The C99 standard includes atoi, atol, atoll, and atof */
    ASSERT_TEST(atoi(" -123") == -123);
    ASSERT_TEST(atol("2147483647") == 2147483647L);
    // ASSERT_TEST(atoll("-9223372036854775807") == -9223372036854775807LL);
    d_val = atof("0.5");
    ASSERT_TEST(d_val == 0.5);

    /* All tests succeeded */
    return 0; 
}