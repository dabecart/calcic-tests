int* p = (void*) 1;
int* p2 = p + 2; /* This would read the memory content of p, which is invalid during the compilation. */

int main() {
    return 0;
}