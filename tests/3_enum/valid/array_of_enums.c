// Exit code: 0
/* Test: Array of enum types. */
enum E { A, B };
int main() {
    enum E arr[3] = { A, B, A };
    if (arr[0] != 0) return 1;
    if (arr[1] != 1) return 2;
    if (arr[2] != 0) return 3;
    return 0;
}