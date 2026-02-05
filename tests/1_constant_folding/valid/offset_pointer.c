// Exit code: 0

struct ComplexNumber {
    float a;
    float b;
};
struct ComplexNumber num = {1.0f, -2.5f};

float* pa = &num.a;
float* pb = &num.b;

struct Vector {
    struct ComplexNumber p1;
    struct ComplexNumber p2;
};

struct Vector vec = {{-5.0f, 7.5f}, {1.0f, 140.2f}};

float* pvec2_a = &vec.p2.a;
float* pvec2_b = &vec.p2.b;

int main() {
    if(*pa != 1.0f) return 1;
    if(*pb != -2.5f) return 2;
    if(*pvec2_a != 1.0f) return 3;
    if(*pvec2_b != 140.2f) return 4;

    return 0;
}