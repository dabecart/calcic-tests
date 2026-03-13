typedef int arr_type[5];
arr_type bad_func(void) {
    static int a[5];
    return a;
}
int main(void) {
    return 0;
}
