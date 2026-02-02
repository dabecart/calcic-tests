void mutate(int *p) {
    *p = 99;
}

int main() {
    const int val = 10;
    mutate(&val); /* ERROR: Cannot pass 'const int *' to 'int *' (discards qualifiers) */
    return 0;
}