// Exit code: 0
/* Test: Enum as array index. */
enum Index { IDX_1, IDX_2 };
int main() {
    int arr[2] = { 100, 200 };
    if (arr[IDX_1] != 100) return 1;
    if (arr[IDX_2] != 200) return 2;
    return 0;
}