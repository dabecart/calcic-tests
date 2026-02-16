// Exit code: 0

int main() {
    union s;
    {
        struct s{int x; int y;} a = {1, 2};
        if(a.x != 1) return 1;
        if(a.y != 2) return 2;
    }

    union s {int i; char c;} b = {0xFE70};
    if(b.i != 0xFE70) return 3;
    if(b.c != 0x70) return 4;

    enum e{RED, GREEN, BLUE} a = RED;
    if(a != 0) return 5;
    {
        enum e b = GREEN;
        if(b != 1) return 6;

        enum e{YELLOW = 10, BLUE, PINK} c = PINK;
        if(c != 12) return 7;
    }

    enum {A = 5, B, C} en = A;
    int x = B;
    int y = C;

    if(en != 5) return 8;
    if(x != 6) return 9;
    if(y != 7) return 10;

    {
        enum {A = 15, B, C} en = A;
        int x = B;
        int y = C;

        if(en != 15) return 11;
        if(x != 16) return 12;
        if(y != 17) return 13;
    }

    return 0;
}
