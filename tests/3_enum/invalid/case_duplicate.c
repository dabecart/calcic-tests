/* Test: Duplicate case labels using enum constants. */
enum E { A = 1, B = 1 };
int main() {
    int x = 1;
    switch(x) {
        case A: break;
        case B: break; // ERROR: Duplicate case value '1'
    }
    return 0;
}