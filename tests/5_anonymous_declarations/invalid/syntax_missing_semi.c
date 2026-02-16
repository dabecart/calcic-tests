int main(void) {
    /* ERROR: Missing semicolon after closing brace */
    struct {
        int a;
    } my_var

    my_var.a = 10;
    return 0;
}
