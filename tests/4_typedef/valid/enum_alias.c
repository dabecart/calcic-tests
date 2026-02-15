// Exit code: 0
enum BaseColors { RED, GREEN, BLUE };
typedef enum BaseColors Color;

int main(void) {
    Color c = GREEN;
    if (c != 1) return 1;
    if (sizeof(c) != sizeof(int)) return 2; // Usually true in C
    return 0;
}