/* ERROR: 'static' not allowed in typedef */
typedef static struct { int x; } MyType;

int main(void) {
    return 0;
}
