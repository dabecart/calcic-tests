// Exit code: 0
typedef enum { RED, GREEN, BLUE } Color;

int main(void) {
    Color c = GREEN;
    if (c != 1) return 1;
    if (sizeof(c) != sizeof(int)) return 2; // Usually true in C
    return 0;
}