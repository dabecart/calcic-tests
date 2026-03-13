// Exit code: 0
union func_store {
    int (*op_int)(int);
    double (*op_double)(double);
};
int square_int(int a) { return a * a; }
int main(void) {
    union func_store store;
    store.op_int = square_int;
    int val = store.op_int(5);
    if(val != 25) return 105;
    return 0;
}
