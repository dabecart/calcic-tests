/* Error: Pointer difference results in ptrdiff_t (int), not float pointer */
void test() {
    float arr[5];
    float *p1 = &arr[0];
    float *p2 = &arr[1];
    float *p3 = p2 - p1; // p2-p1 is an integer type, not a pointer
}