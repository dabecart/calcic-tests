/* Test: Missing closing brace in enum definition. */
enum Status {
    START,
    STOP
// SYNTAX ERROR: Missing '};'
int main() { return 0; }