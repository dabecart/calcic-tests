// Exit code: 0
/* Test default initialization of static/global floats (must be 0.0) */
float global_f;
int main() {
    static float static_f;
    if (global_f != 0.0f) return 1;
    if (static_f != 0.0f) return 2;
    return 0;
}