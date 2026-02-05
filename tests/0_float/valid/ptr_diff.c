// Exit code: 0
/* Test pointer difference */
int main() {
    float arr[5];
    float *start = &arr[0];
    float *end = &arr[4];
    
    long diff = end - start;
    if (diff != 4) return 1;
    return 0;
}