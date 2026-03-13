float ret_float(void) { return 1.0f; }
int main(void) {
    int (*fp)(void) = ret_float;
    return 0;
}
