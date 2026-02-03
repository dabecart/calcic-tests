// Exit code: 0
/* Test basic float arithmetic */
int main() {
    float a = 10.5f;
    float b = 2.5f;
    
    if ((a + b) != 13.0f) return 1;
    if ((a - b) != 8.0f)  return 2;
    if ((a * b) != 26.25f) return 3;
    if ((a / b) != 4.2f)  return 4;
    return 0;
}