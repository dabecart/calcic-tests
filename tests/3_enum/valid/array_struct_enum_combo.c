// Exit code: 0
/* Test: Array of structs containing enums. */
enum Type { T1, T2 };
struct Obj {
    enum Type t;
    int val;
};
int main() {
    struct Obj arr[2] = { {T1, 10}, {T2, 20} };
    if (arr[0].t != 0) return 1;
    if (arr[1].t != 1) return 2;
    return 0;
}