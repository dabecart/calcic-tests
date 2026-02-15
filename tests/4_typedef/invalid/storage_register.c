// Error: typedef cannot be combined with register
int main(void) {
    typedef register int my_int;
    return 0;
}