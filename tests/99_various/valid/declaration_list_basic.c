// Exit code: 0
/* Tests declaration lists and initialization */

int main(void) {
    int x = 10, y = 20, z;
    z = x + y;

    if (z != 30) return 1;

    int a, b = 5, c = 7;
    a = b * c;

    if (a != 35) return 2;

    return 0;
}
