// Exit code: 0
/* Test 1D float array */
int main() {
    float arr[3] = {1.1f, 2.2f, 3.3f};
    
    if (arr[0] != 1.1f) return 1;
    if (arr[1] != 2.2f) return 2;
    if (arr[2] != 3.3f) return 3;
    return 0;
}