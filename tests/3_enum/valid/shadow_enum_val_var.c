// Exit code: 0
/* Test: Local variable shadowing enum constant. */
enum E { VAL = 5 };
int main() {
    int VAL = 10;
    if (VAL != 10) return 1;
    {
        if (VAL != 10) return 2;
    }
    return 0;
}