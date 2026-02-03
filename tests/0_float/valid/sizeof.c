// Exit code: 0
/* Test sizeof operator */
int main() {
    float f;
    if (sizeof(float) == 0) return 1;
    if (sizeof(f) != sizeof(float)) return 2;
    return 0;
}