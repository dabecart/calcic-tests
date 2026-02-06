/* Test: Using a pointer to an enum as an array index (invalid type). */
enum Index { I = 0, J = 1 };
int main() {
    int arr[5];
    enum Index *p = 0;
    int x = arr[p]; // ERROR: Array subscript is not an integer
    return 0;
}