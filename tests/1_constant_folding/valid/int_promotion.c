// Exit code: 0

/* Tests Integer Promotions (checking that char/short perform math as ints) */
unsigned char a = 0xFF;
unsigned char b = 0xFF;
/* If math was done as char: 255+255 = 254 (overflow 8-bit).
   If math done as int: 255+255 = 510. */
int sum = (unsigned char)0xFF + (unsigned char)0xFF;

/* Bitwise shift on small types */
/* (unsigned char)1 is promoted to int. (1 << 10) = 1024.
   If not promoted, 1 << 10 would overflow 8-bit char. */
int shift = (unsigned char)1 << 10;

int main() {
    if (sum != 510) return 1;
    if (shift != 1024) return 2;
    return 0;
}