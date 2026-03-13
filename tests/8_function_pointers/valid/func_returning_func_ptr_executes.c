// Exit code: 0
int magic_number(void) { return 73; }
int (*get_magic_func(void))(void) { return magic_number; }
int main(void) {
    int (*func)(void) = get_magic_func();
    int val = func();
    if(val != 73) return 111;
    return 0;
}
