/* Error: Cannot add a float to a pointer */
void test() {
    int arr[10];
    int *p = arr;
    float f = 1.0f;
    p = p + f;
}