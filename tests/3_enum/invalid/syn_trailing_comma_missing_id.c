/* Test: Trailing comma followed by nothing but closing brace is allowed in C99, 
   but a comma with absolutely no entries is invalid. */
enum Bad { , }; // ERROR: Expected identifier before comma
int main() { return 0; }