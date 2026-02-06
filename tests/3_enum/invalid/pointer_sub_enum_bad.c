/* Test: Subtracting pointers to different enum types. */
enum E1 { A };
enum E2 { B };
int main() {
    enum E1 *p1;
    enum E2 *p2;
    int x = p1 - p2; // ERROR: Pointer subtraction requires pointers to same object type
    return 0;
}