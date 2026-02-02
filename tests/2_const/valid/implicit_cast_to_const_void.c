// Exit code: 10

int main() {
    const int x = 10;
    const void *p = &x;
    const int* px = p;
    return *px;
}