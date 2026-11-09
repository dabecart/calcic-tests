void mama(int a[static const 3]) {
    int x[5];
    a = x;  // Ilegal, a decays to int (const *).
}

int main() {
    return 0;
}