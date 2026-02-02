// Exit code: 0

/* Tests truncation when assigning constant to smaller type */
unsigned char c1 = 257;   /* 257 % 256 = 1 (assuming 8-bit char) */
unsigned char c2 = -1;    /* 255 (11111111) */
unsigned short s1 = 65537; /* 1 (assuming 16-bit short) */

int main() {
    if (c1 != 1) return 1;
    if (c2 != 255) return 2;
    if (s1 != 1) return 3;
    return 0;
}