// Exit code: 0
/* Test increment and decrement on floats */
int main() {
    float f = 1.0f;
    float res = f++; // Post-inc: res=1.0, f=2.0
    if (res != 1.0f) return 1;
    if (f != 2.0f) return 2;
    
    res = ++f; // Pre-inc: res=3.0, f=3.0
    if (res != 3.0f) return 3;
    
    res = f--; // Post-dec: res=3.0, f=2.0
    if (res != 3.0f) return 4;
    if (f != 2.0f) return 5;
    return 0;
}