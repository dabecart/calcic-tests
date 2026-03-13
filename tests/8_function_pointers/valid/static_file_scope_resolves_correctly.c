// Exit code: 0
static int internal_val(void) { return 99; }
static int (*static_op)(void) = internal_val;
int main(void) {
    int val = static_op();
    if(val != 99) return 109;
    return 0;
}
