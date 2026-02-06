/* Test: Using negative enum value as array size. */
enum Sizes { SMALL = -5 };
int main() {
    int arr[SMALL]; // ERROR: Size of array has non-integer (negative) type
    return 0;
}