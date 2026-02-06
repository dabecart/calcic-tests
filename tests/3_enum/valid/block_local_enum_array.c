// Exit code: 0
/* Test: Local enum definition used for local array size. */
int main() {
    enum Test { SZ = 5 };
    int arr[SZ];
    if (sizeof(arr)/sizeof(int) != 5) return 1;
    return 0;
}