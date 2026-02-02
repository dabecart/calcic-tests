/* Standard: C99 6.7.8p4 - Constraints */
const int a = 10;
int b = a; /* Error: 'a' is not a constant expression, even if const */
int main() { return 0; }