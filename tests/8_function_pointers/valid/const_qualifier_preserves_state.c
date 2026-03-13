// Exit code: 0
int ret_10(void) { return 10; }
int main(void) {
    int (*const fixed_ptr)(void) = ret_10;
    int val = fixed_ptr();
    if(val != 10) return 108;
    return 0;
}
