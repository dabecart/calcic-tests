// Error: assignment of read-only variable
typedef const int CInt;
int main(void) {
    CInt x = 5;
    x = 6; 
    return 0;
}