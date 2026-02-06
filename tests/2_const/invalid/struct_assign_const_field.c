/* Test: Assigning to a struct that has a const member. */
struct Config {
    const int id;
    int status;
};

int main() {
    struct Config c1 = {1, 0};
    struct Config c2 = {2, 1};

    // ERROR: Assignment to struct with const member is invalid
    c1 = c2;

    return 0;
}
