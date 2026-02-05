// Exit code: 0.
/* Test: Using const variables as array indices. */
int main() {
    int arr[4] = {10, 20, 30, 40};
    const int idx1 = 1;
    const int idx2 = 3;

    int val1 = arr[idx1];
    int val2 = arr[idx2];

    if (val1 != 20) return 1;
    if (val2 != 40) return 2;

    // Math on const index
    if (arr[idx1 + 1] != 30) return 3;

    return 0;
}
