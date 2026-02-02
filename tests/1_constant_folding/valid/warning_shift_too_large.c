// Exit code: 0

/* Shift count >= width of type is undefined (assuming 32-bit int) */
int x = 1 << 32; 
int main() { 
    return x == 0 ? 0 : 1; 
}