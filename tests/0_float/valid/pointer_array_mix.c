// Exit code: 0
/* Test array of pointers to floats */
int main() {
    float a = 1.0f;
    float b = 2.0f;
    float *arr[2];
    arr[0] = &a;
    arr[1] = &b;
    
    if (*arr[0] != 1.0f) return 1;
    if (*arr[1] != 2.0f) return 2;
    return 0;
}