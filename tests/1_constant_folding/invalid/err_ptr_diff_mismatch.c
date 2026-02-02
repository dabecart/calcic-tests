/* Subtraction of pointers to different objects is not a constant expression */
int a;
int b;
long diff = &a - &b; 
int main() { return 0; }