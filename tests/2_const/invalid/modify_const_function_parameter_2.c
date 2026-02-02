int func(const int * const p, const float f) {
    static int var = 10;
    p = &var;
    return *p + f;
}

int main() {
    int val = 5;
    int strangeSum = func(&val, 10.5f);
    if(strangeSum != 20) {
        return 1;
    }

    return 0;
}