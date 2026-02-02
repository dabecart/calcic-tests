// Exit code: 0

int main() {
    int y = 5;
    int * const p2 = &y;
    *p2 = 8;   
    if(*p2 != 8) {
        return 1;
    }

    int* p3 = p2;
    if(*p3 != 8) {
        return 2;
    }

    return 0;
}