/* Test: Invalid character '@' in enum identifier. */
enum Color {
    RED,
    BLUE,
    GR@EN // LEXICAL ERROR: Illegal character
};
int main() { return 0; }