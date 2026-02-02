// Exit code: 0

/* Tests boolean logic &&, ||, ! */
int l1 = 5 && 2;            /* 1 */
int l2 = 0 || 2;            /* 1 */
int l3 = 5 && 0;            /* 0 */
int l4 = 0 || 0;            /* 0 */
int l5 = !0;                /* 1 */
int l6 = !55;               /* 0 */
int l7 = !!55;              /* 1 */
int l8 = 1 || 0 && 0;       /* 1 */

int main() {
    if (l1 != 1) return 1;
    if (l2 != 1) return 2;
    if (l3 != 0) return 3;
    if (l4 != 0) return 4;
    if (l5 != 1) return 5;
    if (l6 != 0) return 6;
    if (l7 != 1) return 7;
    if (l8 != 1) return 8;
    return 0;
}