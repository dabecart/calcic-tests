// Exit code: 0
/* Test float to int cast (truncation) */
int main() {
    float f = 5.9f;
    int i = (int)f;
    if (i != 5) return 1;
    
    f = -f;
    i = (int)f;
    if (i != -5) return 2;
    return 0;
}