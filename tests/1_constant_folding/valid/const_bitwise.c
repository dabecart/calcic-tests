// Exit code: 0

/* Tests bitwise logic and shifts */
int b1 = 5 << 2;            /* 20 */
int b2 = 48 >> 3;           /* 6 */
int b3 = 54 & 21;           /* 20 */
int b4 = 5 | 2;             /* 7 */
int b5 = 5 ^ 2;             /* 7 */
int b6 = ~0;                /* -1 */
int b7 = 0x0F & 0xF0;       /* 0 */
int b8 = (1 << 3) | 1;      /* 9 */

int main() {
    if (b1 != 20) return 1;
    if (b2 != 6) return 2;
    if (b3 != 20) return 3;
    if (b4 != 7) return 4;
    if (b5 != 7) return 5;
    if (b6 != -1) return 6;
    if (b7 != 0) return 7;
    if (b8 != 9) return 8;
    return 0;
}