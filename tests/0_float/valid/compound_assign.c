// Exit code: 0
/* Test compound assignment operators */
int main() {
    float f = 10.0f;
    f += 5.0f;
    if (f != 15.0f) return 1;
    f /= 3.0f;
    if (f != 5.0f) return 2;
    f -= 1.0f;
    if (f != 4.0f) return 3;
    f *= 2.5f;
    if (f != 10.0f) return 4;
    return 0;
}