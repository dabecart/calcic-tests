// Exit code: 0

int main() {
    int x = 50;
    const int* const px = (const int* const const) &x;
    const int* const * ppx = &px;
    
    if(**ppx != 50) {
        return 1;
    }

    int y = 10;
    int* const py = &y;
    *py += 100;
    if(*py != 110) {
        return 2;
    }
    return 0;
}