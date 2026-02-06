// Exit code: 0
/* Test: Switch fallthrough with enums. */
enum Steps { S1, S2, S3 };
int main() {
    int val = 0;
    enum Steps s = S1;
    switch(s) {
        case S1: val += 1;
        case S2: val += 1;
        case S3: val += 1;
    }
    if (val != 3) return 1;
    return 0;
}