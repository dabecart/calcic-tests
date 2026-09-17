
int main(void) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    if (sum != 55) return 1;

    int w = 10;
    int w_sum = 0;
    while (w > 0) {
        w_sum += w;
        w--;
    }
    if (w_sum != 55) return 2;

    int d = 0;
    do {
        d++;
    } while (d < 5);
    if (d != 5) return 3;

    int val = 2;
    int res = 0;
    switch (val) {
        case 1: res = 10; break;
        case 2: res = 20; break;
        default: res = 30; break;
    }
    if (res != 20) return 4;

    int skip = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        if (i == 4) break;
        skip++;
    }
    if (skip != 3) return 5;

    return 0;
}
