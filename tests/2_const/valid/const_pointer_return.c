// Exit code: 0

const float* func1() {
    static float constFloat = 10.5f;
    return &constFloat; 
}

const double* func2() {
    static double constDouble = 1210.4;
    return &constDouble; 
}

int main() {
    const float* f = func1();
    const double* d = func2();
    if(*f != 10.5f) {
        return 1;
    }

    if(*d != 1210.4) {
        return 2;
    }

    return 0;
}