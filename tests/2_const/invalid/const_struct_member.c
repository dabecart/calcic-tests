/* Test: Assignment to a const member of a struct. */
struct Data {
    int id;
    const int value;
};

void test() {
    struct Data d = {1, 100};
    d.id = 2; // OK
    
    // ERROR: Assignment of read-only member 'value'
    d.value = 200;
}

int main() {
    return 0;
}