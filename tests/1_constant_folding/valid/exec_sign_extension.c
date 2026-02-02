// Exit code: 0

/* Tests sign extension during promotion */
unsigned int res1 = (unsigned int)(short)-1; 
/* (short)-1 is 0xFFFF. 
   Promoting to int preserves -1 (0xFFFFFFFF). 
   Casting to unsigned int gives UINT_MAX. */

unsigned int res2 = (unsigned int)(unsigned short)-1;
/* (unsigned short)-1 is 65535 (0xFFFF).
   Promoting to int gives 65535.
   Casting to unsigned int gives 65535. */

int main() {
    /* Assuming 32-bit int/unsigned and 16-bit short */
    if (res1 != 0xFFFFFFFF) return 1; 
    if (res2 != 65535) return 2;
    return 0;
}