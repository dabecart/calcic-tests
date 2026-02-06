/* Test: Taking address of an enum constant. */
enum E { A };
int main() {
    int *p = &A; // ERROR: Cannot take address of rvalue (enumerator)
    return 0;
}