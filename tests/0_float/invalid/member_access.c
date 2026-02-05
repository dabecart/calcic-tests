/* Error: Request for member 'x' in something not a struct/union */
void test() {
    float f = 1.0f;
    f.x = 2;
}