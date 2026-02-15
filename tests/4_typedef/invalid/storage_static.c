// Error: multiple storage classes in declaration specifiers
int main(void) {
    typedef static int my_int; 
    return 0;
}