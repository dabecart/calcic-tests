// Error: duplicate member name
typedef int I;
struct S {
    I x;
    float x; 
};
int main(void) { return 0; }