// Exit code: 0
typedef unsigned int UInt;
typedef unsigned char UChar;

int main(void) {
    UInt u = -1; // Wraps around
    if (u <= 0) return 1;
    return 0;
}