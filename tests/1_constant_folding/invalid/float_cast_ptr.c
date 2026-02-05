/* Casting a pointer to a floating point is not a constant expression */
int a;
float f = (float)&a;
int main() { return 0; }