/* Error: Assignment of read-only variable */
int main() {
    const float f = 1.0f;
    f = 2.0f;
    return 0;
}