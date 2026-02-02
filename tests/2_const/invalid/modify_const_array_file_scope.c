const int arr[3] = {1, 2, 3};

int main() {
    arr[0] = 5; /* ERROR: Assignment of read-only location 'arr[0]' */
    return 0;
}