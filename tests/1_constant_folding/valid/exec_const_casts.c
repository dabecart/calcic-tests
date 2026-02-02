// Exit code: 0

/* Tests casting in constant expressions */
int c1 = (int)3.14;         /* 3 */
float c2 = (float)5;        /* 5.0 */
int c3 = (char)257;         /* 1 (assuming 8-bit char) */
int c4 = (int)(char)-1;     /* -1 (sign extension) */

int main() {
    if (c1 != 3) return 1;
    if (c2 != 5.0f) return 2;
    if (c3 != 1) return 3;
    if (c4 != -1) return 4;
    return 0;
}