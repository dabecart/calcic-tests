// Exit code: 0
int global_func(void) { return 1; }
int local_func(void) { return 2; }
int (*ptr)(void) = global_func;
int main(void) {
    int (*ptr)(void) = local_func;
    int val = ptr();
    if(val != 2) return 110;
    return 0;
}
