// Exit code: 0
/* Tests declaration lists and initialization */

int main(void) {
    int x = 10, y = 20, z = x + y;

    if (z != 30) return 1;

    int a = z, b = 5, c = 7;
    if(a != 30) return 2;

    a = b * c;
    if (a != 35) return 3;

    return 0;
}
