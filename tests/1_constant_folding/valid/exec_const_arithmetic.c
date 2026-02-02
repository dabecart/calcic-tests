// Exit code: 0

/* Tests standard BEDMAS/PEMDAS rules */
int c1 = 1 + 2;             /* 3 */
int c2 = 5 - 2;             /* 3 */
int c3 = 5 * 2;             /* 10 */
int c4 = 10 / 2;            /* 5 */
int c5 = 5 % 2;             /* 1 */
int c6 = 2 + 3 * 4;         /* 14 */
int c7 = (2 + 3) * 4;       /* 20 */
int c8 = 10 - 2 + 3;        /* 11 */
int c9 = 10 / 2 * 3;        /* 15 */
int c10 = -5 + 10;          /* 5 */
int c11 = +5 + 5;           /* 10 */

int main() {
    if (c1 != 3) return 1;
    if (c2 != 3) return 2;
    if (c3 != 10) return 3;
    if (c4 != 5) return 4;
    if (c5 != 1) return 5;
    if (c6 != 14) return 6;
    if (c7 != 20) return 7;
    if (c8 != 11) return 8;
    if (c9 != 15) return 9;
    if (c10 != 5) return 10;
    if (c11 != 10) return 11;
    return 0;
}