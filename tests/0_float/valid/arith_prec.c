// Exit code: 0
/* Test operator precedence */
int main() {
    float val = 2.0f + 3.0f * 4.0f; // Should be 14.0, not 20.0
    if (val != 14.0f) return 1;
    
    float val2 = (2.0f + 3.0f) * 4.0f; // Should be 20.0
    if (val2 != 20.0f) return 2;
    return 0;
}