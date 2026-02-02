struct Point {
    int x;
    int y;
};

int main() {
    const struct Point arr[3] = {{0, 1}, {2, 3}, {4, 5}};
    arr[1].x = 5; /* ERROR: Assignment of read-only location 'arr[0]' */
    return 0;
}