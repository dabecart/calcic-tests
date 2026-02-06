/* Test: Passing struct to function expecting enum. */
enum E { A };
struct S { int x; };
void func(enum E e) {}
int main() {
    struct S s;
    func(s); // ERROR: Incompatible type for argument 1
    return 0;
}