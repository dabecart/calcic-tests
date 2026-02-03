/* Error: Cannot subtract a float from a pointer */
void test() {
    int arr[10];
    int *p = arr;
    float f = 1.0f;
    p = p - f;
}