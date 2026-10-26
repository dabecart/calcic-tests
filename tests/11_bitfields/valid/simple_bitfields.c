struct UnsStruct {
    unsigned short a: 3;
    unsigned short b: 4;
    unsigned int c: 8;
    unsigned int d: 3;
    unsigned int x;
};

struct SignStruct {
    short a: 3;
    short b: 4;
    int c: 8;
    int d: 3;
    int x;
};

struct UnsStruct u = {1, 2, 3, 4, 5};
struct SignStruct s = {-1, -2, -3, -4, -5};

int main() {
    if (u.a != 1) return 1;
    if (u.b != 2) return 2;
    if (u.c != 3) return 3;
    if (u.d != 4) return 4;
    if (u.x != 5) return 5;

    if (s.a != -1) return 10;
    if (s.b != -2) return 20;
    if (s.c != -3) return 30;
    if (s.d != -4) return 40;
    if (s.x != -5) return 50;

    return 0;
}