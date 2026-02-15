// Error: function type cannot be const qualified directly (refers to function itself, not return type)
typedef void F(void);
typedef const F CF; 
int main(void) { return 0; }