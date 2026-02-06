// Exit code: 0
/* Test: Union of array and single enum. */
enum E { A=1, B=2 };
union U {
    enum E vals[2];
    enum E first;
};
int main() {
    union U u;
    u.vals[0] = A;
    u.vals[1] = B;
    if (u.first != 1) return 1;
    return 0;
}