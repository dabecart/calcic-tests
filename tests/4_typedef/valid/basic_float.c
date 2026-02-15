// Exit code: 0
typedef float MyFloat;
typedef double MyDouble;

int main(void) {
    MyFloat f = 1.5f;
    MyDouble d = 3.14;
    
    if (f < 1.4f || f > 1.6f) return 1;
    if (d < 3.13 || d > 3.15) return 2;
    return 0;
}