/* Test: Redefining the same enum tag in the same scope. */
enum Status { ON, OFF };
enum Status { YES, NO }; // ERROR: Refinition of 'enum Status'
int main() { return 0; }