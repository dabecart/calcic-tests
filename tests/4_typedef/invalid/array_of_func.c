// Error: array of functions is invalid
typedef void func(void);
typedef func arr[5]; 
int main(void) { return 0; }