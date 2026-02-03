/* Error: Switch expression cannot be float */
void test() {
    float f = 1.0f;
    switch(f) {
        case 1: break;
    }
}