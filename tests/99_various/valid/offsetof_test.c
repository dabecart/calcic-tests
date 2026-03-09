// Exit code: 0
#include <stddef.h>

struct Simple {
    char a;
    double b;
    int c;
};

int test_simple_struct(void) {
    struct Simple s;
    if (offsetof(struct Simple, a) != (size_t)((char*)&s.a - (char*)&s)) return 1;
    if (offsetof(struct Simple, b) != (size_t)((char*)&s.b - (char*)&s)) return 2;
    if (offsetof(struct Simple, c) != (size_t)((char*)&s.c - (char*)&s)) return 3;
    return 0;
}

struct WithArrays {
    short a[5];
    char b;
    long c[3];
};

int test_arrays(void) {
    struct WithArrays s;
    if (offsetof(struct WithArrays, a) != (size_t)((char*)&s.a - (char*)&s)) return 1;
    // C99 allows array indices in offsetof if they are integer constant expressions
    if (offsetof(struct WithArrays, a[3]) != (size_t)((char*)&s.a[3] - (char*)&s)) return 2;
    if (offsetof(struct WithArrays, b) != (size_t)((char*)&s.b - (char*)&s)) return 3;
    if (offsetof(struct WithArrays, c[2]) != (size_t)((char*)&s.c[2] - (char*)&s)) return 4;
    return 0;
}

struct Inner {
    float x;
    float y;
};

struct Outer {
    char prefix;
    struct Inner inner;
    char suffix;
};

int test_nested_structs(void) {
    struct Outer s;
    if (offsetof(struct Outer, inner) != (size_t)((char*)&s.inner - (char*)&s)) return 1;
    if (offsetof(struct Outer, inner.x) != (size_t)((char*)&s.inner.x - (char*)&s)) return 2;
    if (offsetof(struct Outer, inner.y) != (size_t)((char*)&s.inner.y - (char*)&s)) return 3;
    if (offsetof(struct Outer, suffix) != (size_t)((char*)&s.suffix - (char*)&s)) return 4;
    return 0;
}

struct WithUnion {
    int type;
    union {
        char c;
        double d;
        int i[4];
    } u;
};

int test_unions(void) {
    struct WithUnion s;
    if (offsetof(struct WithUnion, u) != (size_t)((char*)&s.u - (char*)&s)) return 1;
    if (offsetof(struct WithUnion, u.c) != (size_t)((char*)&s.u.c - (char*)&s)) return 2;
    if (offsetof(struct WithUnion, u.d) != (size_t)((char*)&s.u.d - (char*)&s)) return 3;
    if (offsetof(struct WithUnion, u.i[2]) != (size_t)((char*)&s.u.i[2] - (char*)&s)) return 4;
    return 0;
}

struct ComplexNode {
    char tag;
    union {
        struct {
            short id;
            char name[16];
        } user;
        struct {
            long hash;
            float weights[3];
        } data;
    } payload[2];
    void *next;
};

int test_complex_hierarchy(void) {
    struct ComplexNode s;
    if (offsetof(struct ComplexNode, payload) != (size_t)((char*)&s.payload - (char*)&s)) return 1;
    
    // Deeply nested access
    if (offsetof(struct ComplexNode, payload[0].user) != 
        (size_t)((char*)&s.payload[0].user - (char*)&s)) return 2;
        
    if (offsetof(struct ComplexNode, payload[0].user.name[5]) != 
        (size_t)((char*)&s.payload[0].user.name[5] - (char*)&s)) return 3;
        
    if (offsetof(struct ComplexNode, payload[1].data.weights[2]) != 
        (size_t)((char*)&s.payload[1].data.weights[2] - (char*)&s)) return 4;
        
    if (offsetof(struct ComplexNode, next) != 
        (size_t)((char*)&s.next - (char*)&s)) return 5;
        
    return 0;
}

int main(void) {
    if (test_simple_struct() != 0)      return 1;
    if (test_arrays() != 0)             return 2;
    if (test_nested_structs() != 0)     return 3;
    if (test_unions() != 0)             return 4;
    if (test_complex_hierarchy() != 0)  return 5;

    return 0;
}