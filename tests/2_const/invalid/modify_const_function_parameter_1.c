int func(const char c, const float f) {
    c = 10;
    return c + f;
}

int main() {
    return func('a', 10.5f);
}