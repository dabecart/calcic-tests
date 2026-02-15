// Error: function cannot return function type
typedef void func_t(void);
typedef func_t getter(void); 
int main(void) { return 0; }