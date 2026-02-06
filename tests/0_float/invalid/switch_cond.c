/* Error: Switch expression cannot be float */
int main() {
    float f = 1.0f;
    switch(f) {
        case 1: break;
    }
    return 0;
}