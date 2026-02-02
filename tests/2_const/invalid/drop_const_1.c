const int* get_ptr() {
    static const int x = 15;
    return &x; // OK: types match
}

int main() {
    int* ptr = get_ptr(); // ERROR: This drops the const!
    return *ptr == 15;
}