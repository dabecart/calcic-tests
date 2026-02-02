// Exit code: 0

/* Tests ?: operator */
int t1 = 1 ? 10 : 20;       /* 10 */
int t2 = 0 ? 10 : 20;       /* 20 */
int t3 = (5 > 2) ? 5 : 2;   /* 5 */
int t4 = 1 ? (0 ? 3 : 4) : 5; /* 4 */

int main() {
    if (t1 != 10) return 1;
    if (t2 != 20) return 2;
    if (t3 != 5)  return 3;
    if (t4 != 4)  return 4;
    return 0;
}