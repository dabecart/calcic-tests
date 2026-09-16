#include <stdint.h>

int main(void) {
    uint32_t a = 0x0F0F0F0F;
    uint32_t b = 0x33333333;

    if ((a & b) != 0x03030303) return 1;
    if ((a | b) != 0x3F3F3F3F) return 2;
    if ((a ^ b) != 0x3C3C3C3C) return 3;
    if (~a != 0xF0F0F0F0) return 4;

    uint32_t shift_val = 0x000000FF;
    if ((shift_val << 8) != 0x0000FF00) return 5;
    if ((shift_val >> 4) != 0x0000000F) return 6;

    int32_t signed_val = -128; // 0xFFFFFF80
    if ((signed_val >> 1) != -64) return 7; // Arithmetic shift right

    return 0;
}
