/* Error: Initializing float member with incompatible struct */
struct S { int a; };
union U { float f; };
void test() {
    struct S s;
    union U u = s; 
}