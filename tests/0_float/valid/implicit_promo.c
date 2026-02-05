// Exit code: 0
/* Test implicit promotion in arithmetic */
int main() {
    int i = 2;
    float f = 5.5f;
    float res = f / i; // i promotes to float (2.0)
    if (res != 2.75f) return 1;
    return 0;
}