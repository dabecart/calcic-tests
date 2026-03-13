// Exit code: 0
int op_a(void) { return 100; }
int op_b(void) { return 200; }
int (*get_a(void))(void) { return op_a; }
int (*get_b(void))(void) { return op_b; }
int main(void) {
    int (*(*arr[2])(void))(void) = {get_a, get_b};
    int val1 = arr[0]()();
    if(val1 != 100) return 115;
    int val2 = arr[1]()();
    if(val2 != 200) return 116;
    return 0;
}
