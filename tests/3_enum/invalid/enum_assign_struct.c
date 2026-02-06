/* Test: Assigning a struct to an enum variable. */
enum E { A };
struct S { int x; };
int main() {
    enum E e;
    struct S s;
    e = s; // ERROR: Incompatible types in assignment
    return 0;
}