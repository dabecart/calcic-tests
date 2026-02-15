// Error: Cannot take address of bitfield (or create pointer to it via typedef directly if attempted oddly)
// Actually, standard C: bitfields are struct declarators. 
// This tests creating a typedef to a bitfield member type which is invalid syntax directly.
struct S {
    typedef int bit : 3; // syntax error: typedef inside struct field decl
};
int main(void) { return 0; }