/* Error: Initializing float member with incompatible struct */
struct S { int a; };
union U { float f; };
int main() {
    struct S s;
    union U u = s; 
    return 0;
}