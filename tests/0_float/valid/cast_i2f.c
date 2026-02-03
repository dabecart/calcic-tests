// Exit code: 0
/* Test int to float cast */
int main() {
    int i = 100;
    float f = (float)i;
    if (f != 100.0f) return 1;
    return 0;
}