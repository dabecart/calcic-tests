// Exit code: 0
/* Test 2D arrays */
int main() {
    float mat[2][2] = { {1.0f, 2.0f}, {3.0f, 4.0f} };
    if (mat[1][0] != 3.0f) return 1;
    return 0;
}