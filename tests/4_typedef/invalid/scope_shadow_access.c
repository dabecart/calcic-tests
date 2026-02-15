// Error: attempting to access shadowed type
typedef int T;
int main(void) {
    typedef float T;
    // This should fail if we try to assign int* to T* (which is float*)
    // But to make it a grammar/type error clearly:
    T val = 5.5;
    int *p = &val; // Warning or Error: incompatible pointer types
    // To force error without -Werror, let's try something structural
    T arr[2.5]; // Error: array size must be integer (float is T)
    return 0;
}