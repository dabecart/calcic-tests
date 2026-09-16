
int main(void) {
    float f1 = 5.5f, f2 = 2.0f;
    if (f1 + f2 != 7.5f) return 1;
    if (f1 - f2 != 3.5f) return 2;
    if (f1 * f2 != 11.0f) return 3;
    if (f1 / f2 != 2.75f) return 4;

    double d1 = 1.0, d2 = 3.0;
    double d3 = d1 / d2;
    if (d3 < 0.333 || d3 > 0.334) return 5;

    int float_to_int = (int)(f1);
    if (float_to_int != 5) return 6;

    float int_to_float = (float)(float_to_int);
    if (int_to_float != 5.0f) return 7;

    return 0;
}
