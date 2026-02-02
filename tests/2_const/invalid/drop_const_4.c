int main() {
    int *ptr;
    // ERROR: converting 'int **' to 'const int **' is NOT safe in C without a cast.
    const int **pp = &ptr; 
    return 0;
}