// In a function prototype (declaration), top-level const is ignored for compatibility.

/* Header File */
void compute(int x); // The 'const' doesn't matter here

/* Source File */
void compute(const int x) {
    x = 10; // This would be an error here
}

int main() {
    return 0;
}