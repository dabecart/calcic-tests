// Exit code: 0
// Global static initialization of tagless structs.
struct { int a; int b; } global_anon = { 100, 200 };

typedef struct { int k; } Key;
static Key global_key = { 777 };

int main(void) {
    if (global_anon.a != 100) return 1;
    if (global_anon.b != 200) return 2;
    if (global_key.k != 777) return 3;
    return 0;
}
