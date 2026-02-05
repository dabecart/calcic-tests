// Exit code: 0
/* Test nested structs */
struct Inner { float f; };
struct Outer { struct Inner in; float scale; };

int main() {
    struct Outer out = { {1.5f}, 2.0f };
    
    if (out.in.f != 1.5f) return 1;
    if ((out.in.f * out.scale) != 3.0f) return 2;
    return 0;
}