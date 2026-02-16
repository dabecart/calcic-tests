// Anonymous member (struct/union without name) inside another struct.
// This is valid in C11/C23, but INVALID in C99.

struct Container {
    int id;
    struct { int x; int y; }; /* ERROR: C99 requires a member name here */
};

int main(void) {
    return 0;
}
