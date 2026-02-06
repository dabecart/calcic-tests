/* Test: Identifier starting with a digit. */
enum Math {
    1ST_PLACE // LEXICAL ERROR: ID cannot start with digit
};
int main() { return 0; }