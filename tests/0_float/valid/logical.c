// Exit code: 0
/* Test floats in logical expressions */
int main() {
    float zero = 0.0f;
    float non_zero = 0.1f;
    
    if (zero) return 1;      // Should be false
    if (!non_zero) return 2; // Should be false
    return 0;
}