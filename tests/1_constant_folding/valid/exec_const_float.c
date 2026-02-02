// Exit code: 0

/* Tests floating point arithmetic folding */
float f1 = 1.5 + 2.5;       /* 4.0 */
float f2 = 5.0 / 2.0;       /* 2.5 */
int f3 = 1.5 < 2.5;         /* 1 */
double f4 = 3.0 * 1.5;      /* 4.5 */

int main() {
    if (f1 != 4.0f) return 1;
    if (f2 != 2.5f) return 2;
    if (f3 != 1) return 3;
    if (f4 != 4.5) return 4;
    return 0;
}