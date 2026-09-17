
int main(void) {
    int val = 1337;
    int *p1 = &val;
    if (*p1 != 1337) return 1;

    *p1 = 42;
    if (val != 42) return 2;

    int **p2 = &p1;
    if (**p2 != 42) return 3;

    int arr[5] = {10, 20, 30, 40, 50};
    int *pa = arr;
    if (*pa != 10) return 4;
    
    pa++;
    if (*pa != 20) return 5;

    if (pa[2] != 40) return 6;

    pa += 2;
    if (*pa != 40) return 7;

    if (pa - arr != 3) return 8;

    return 0;
}
