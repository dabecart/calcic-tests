int main() {
    int val = 10, other = 11, *p1 = &val, * const p2 = p1;

    p1 = &other;
    p2 = &other;    // Error: trying to modify a const pointer.
    
    return 0;
}