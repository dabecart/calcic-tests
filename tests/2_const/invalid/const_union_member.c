/* Test: Modifying a member of a const union. */
union Converter {
    int i;
    float f;
};

void test() {
    const union Converter u = { 10 };
    
    // ERROR: Assignment of member 'i' in read-only object
    u.i = 20;
}

int main() {
    return 0;
}