// Exit code: 0

/* sizeof must be evaluated at compile time */
int s1 = sizeof(char);           /* 1 */
int s2 = sizeof(int);            /* 4 */
int s3 = sizeof(long);           /* 8 */
int s4 = sizeof(char[10]);       /* 10 */
int s5 = sizeof(1 + 2);          /* sizeof(int) */

int main() {
    if (s1 != 1) return 1;
    if (s2 != 4) return 2;
    if (s3 != 8) return 3;
    if (s4 != 10) return 4;
    if (s5 != sizeof(int)) return 5;
    return 0;
}