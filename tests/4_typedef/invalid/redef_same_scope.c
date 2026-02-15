// Error: redefinition of identifier 'A' in same scope (C99 constraint)
int main(void) {
    typedef int A;
    typedef int A; 
    return 0;
}