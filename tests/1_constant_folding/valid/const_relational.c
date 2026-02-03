// Exit code: 0

/* Tests <, >, <=, >=, ==, != */
int r1 = 5 > 2;             /* 1 */
int r2 = 1 >= 2;            /* 0 */
int r3 = 5 < 2;             /* 0 */
int r4 = 2 <= 2;            /* 1 */
int r5 = 5 == 2;            /* 0 */
int r6 = 5 != 2;            /* 1 */
int r7 = 5 > 2 == 1;        /* 1 */

int main() {
    if (r1 != 1) return 1;
    if (r2 != 0) return 2;
    if (r3 != 0) return 3;
    if (r4 != 1) return 4;
    if (r5 != 0) return 5;
    if (r6 != 1) return 6;
    if (r7 != 1) return 7;
    return 0;
}