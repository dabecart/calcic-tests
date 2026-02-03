// Exit code: 0
/* Test short-circuit evaluation with floats */
int main() {
    float f = 1.0f;
    int check = 0;
    
    // 0.0 is false, right side should NOT execute
    if (0.0f && (check = 1)) {} 
    if (check == 1) return 1;
    
    // 1.0 is true, right side SHOULD execute
    if (1.0f && (check = 1)) {}
    if (check != 1) return 2;
    
    return 0;
}