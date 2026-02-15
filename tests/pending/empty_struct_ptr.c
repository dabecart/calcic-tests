// Exit code: 0
// Opaque pointer pattern
typedef struct Hidden * Handle;
struct Hidden { int id; };

int main(void) {
    struct Hidden h = {77};
    Handle ptr = &h;
    if (ptr->id != 77) return 1;
    return 0;
}