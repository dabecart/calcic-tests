union Config {
    const int id;
    int status;
};

int main() {
    union Config c1 = {1};
    union Config c2 = {2};

    // ERROR: Assignment to an union with const member is invalid
    c1 = c2;

    return 0;
}
