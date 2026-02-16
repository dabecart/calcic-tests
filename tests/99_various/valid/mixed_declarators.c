// Exit code: 0
/* Mixed declarators: pointers and arrays */

int main(void) {
    int x = 5, *p = &x, arr[3] = {1,2,3};

    if (*p != 5) return 1;
    if (arr[2] != 3) return 2;

    return 0;
}
