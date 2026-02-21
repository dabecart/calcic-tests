// Exit code: 0
typedef int IntArray[3];

int func(IntArray arg) {
    if(arg[0] != 1) return 0;
    return 1;
}

int main() {
    IntArray a = {1, 2, 3};

    int *p = a;

    if(a[2] != 3) return 1;
    if(!func(a)) return 2;

    return 0;
}