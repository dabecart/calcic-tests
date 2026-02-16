// Attempting to modify a member of a const tagless struct.
typedef struct { int x; } S;

int main(void) {
    const S s = { 10 };
    
    /* ERROR: Assignment of read-only member 'x' */
    s.x = 20; 
    
    return 0;
}
