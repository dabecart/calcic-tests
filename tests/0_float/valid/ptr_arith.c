// Exit code: 0
/* Test pointer arithmetic on float pointers */
int main() {
    float arr[3] = {10.0f, 20.0f, 30.0f};
    float *p = arr;
    
    if (*p != 10.0f) return 1;
    p++;
    if (*p != 20.0f) return 2;
    p += 1;
    if (*p != 30.0f) return 3;
    return 0;
}