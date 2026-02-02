/* Function calls are not constant expressions */
int foo() { return 5; }
int x = foo();
int main() { return 0; }