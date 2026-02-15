// Exit code: 0
typedef int RetType;
RetType get_val(void) { return 42; }

int main(void) {
    if (get_val() != 42) return 1;
    return 0;
}