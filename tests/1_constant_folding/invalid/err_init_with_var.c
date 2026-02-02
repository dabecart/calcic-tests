/* Global variables cannot be initialized with other variables */
int a = 10;
int b = a + 5; /* Error: 'a' is not a constant expression */
int main() { return 0; }