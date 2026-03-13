// Exit code: 0
int ret_42(void) { return 42; }
int main(void) {
    int (*func_ptr)(void) = ret_42;
    int (**ptr_to_func)(void) = &func_ptr;
    int val = (*ptr_to_func)();
    if(val != 42) return 106;
    return 0;
}
