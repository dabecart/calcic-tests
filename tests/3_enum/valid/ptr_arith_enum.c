// Exit code: 0
/* Test: Pointer arithmetic over enum array. */
enum E { X, Y, Z };
int main() {
    enum E arr[3] = { X, Y, Z };
    enum E *p = arr;
    if (*p != 0) return 1;
    p++;
    if (*p != 1) return 2;
    p++;
    if (*p != 2) return 3;
    return 0;
}