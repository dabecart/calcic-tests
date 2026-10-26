/* Valid: Bitfield value truncation on overflow */
struct S {
    unsigned int a : 3; /* max value 7 */
};

int main(void) {
    struct S s;
    s.a = 10; /* binary 1010, truncated to 3 bits -> 010 (2) */
    if (s.a != 2) return 1;
    return 0;
}
