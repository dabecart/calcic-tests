/* Test: Writing to an element of a const array. */
void test() {
    const int arr[] = {1, 2, 3};
    
    // ERROR: Assignment of read-only location 'arr[1]'
    arr[1] = 5;
}

int main() {
    return 0;
}