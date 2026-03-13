int take_float(float f) { return (int)f; }
int main(void) {
    int (*fp)(int) = take_float;
    return 0;
}
