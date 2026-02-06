// Exit code: 0
/* Test: Switch case using enum constants. */
enum Ops { ADD, SUB, MUL };
int main() {
    enum Ops op = SUB;
    int res = 0;
    switch(op) {
        case ADD: res = 1; break;
        case SUB: res = 2; break;
        case MUL: res = 3; break;
        default: res = 0;
    }
    if (res != 2) return 1;
    return 0;
}