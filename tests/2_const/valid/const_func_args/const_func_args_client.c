// Exit code: 0

/* Function promises not to modify the data */
void process_data(const int *p); 

int main() {
    int x = 42;
    process_data(&x); /* Valid: int* -> const int* */
    if (x != 42) return 1;
    return 0;
}