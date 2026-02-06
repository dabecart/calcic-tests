// Exit code: 0
/* Test: Enum as array size. */
enum Size { S = 10 };
int main() {
    int arr[S];
    int i;
    for(i=0; i<S; i++) arr[i] = i;
    if (arr[9] != 9) return 1;
    if (sizeof(arr) != 10 * sizeof(int)) return 2;
    return 0;
}