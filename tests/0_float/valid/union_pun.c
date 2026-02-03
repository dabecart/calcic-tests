// Exit code: 0
/* Test union type punning/overlay */
union U {
    float f;
    unsigned int i;
};

int main() {
    union U u;
    u.f = 0.0f; // IEEE 754 0.0 is integer 0x00000000
    if (u.i != 0) return 1;
    
    u.i = 0;
    u.f = 123.456f;
    if (u.i == 0) return 2; 
    return 0;
}