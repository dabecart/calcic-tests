// Even though the arguments aren't exactly the same, this is valid.
void mama(int a[]);

void mama(int a[static const 3]) {
    int x[5];
    a[2] = 3;
}

int main() {
    int x[5];
    mama(x);
    if (x[2] != 3) {
        return 1;
    }
    return 0;
}