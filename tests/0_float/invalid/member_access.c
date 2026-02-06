/* Error: Request for member 'x' in something not a struct/union */
int main() {
    float f = 1.0f;
    f.x = 2;
    return 0;
}