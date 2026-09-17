// #define TEST_LONG
// #define TEST_LONG_LONG

// --- Structures, Unions, and Typedefs ---

struct StructArray { 
    int a; 
    int b[3]; 
};

union UnionData { 
    unsigned int i; 
    unsigned char c[sizeof(unsigned int)]; 
};

struct FixedArray { 
    int count; 
    int data[4]; 
};

union ArrayOverlay {
    struct { int count; int data[4]; } fixed;
    struct FixedArray flex;
};

// struct BitFieldLayout {
//     unsigned int a : 3;
//     unsigned int b : 5;
//     unsigned int c : 24;
// };

union ArrayUnion { 
    int i; 
    short f; 
};

typedef int (*OpFunc)(int, int);

struct FuncStruct {
    OpFunc op;
    int arr[2];
};

// --- Helper Functions ---

int sum_array(int a[4], int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    return s;
}

int process_matrix(int m[2][3], int rows) {
    int s = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 3; ++j) {
            s += m[i][j];
        }
    }
    return s;
}

int process_static(int a[3]) {
    return a[0] + a[1] + a[2];
}

int op_add(int a, int b) { return a + b; }
int op_sub(int a, int b) { return a - b; }

// --- Main CPU Test ---

int main(void) {
    // 1-4: Basic Array Initialization and Multi-dimensional Access
    int arr1[4] = {1, 2, 3, 4};
    if (arr1[0] != 1 || arr1[3] != 4) return 1;

    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    if (mat[0][2] != 3) return 2;
    if (mat[1][1] != 5) return 3;

    int sum = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            sum += mat[i][j];
        }
    }
    if (sum != 21) return 4;

    // 5-7: C99 Designated Initializers
    // int desig[6] = { [1] = 10, [5] = 50, [3] = 30 };
    // if (desig[0] != 0) return 5;
    // if (desig[1] != 10) return 6;
    // if (desig[5] != 50) return 7;

    // 8-9: Array Decay and Pointer Arithmetic
    int *p1 = arr1;
    if (*(p1 + 2) != 3) return 8;
    if (p1[1] != 2) return 9;

    // 10-11: Pointer to Array
    int (*p2)[3] = &mat[1];
    if ((*p2)[0] != 4) return 10;
    if ((*p2)[2] != 6) return 11;

    // 12: Array of Pointers
    int v1 = 100, v2 = 200, v3 = 300;
    int *arr_ptr[3] = {&v1, &v2, &v3};
    if (*arr_ptr[1] != 200) return 12;

    // 13-14: Structs containing Arrays and Arrays of Structs
    struct StructArray s1 = { 10, {20, 30, 40} };
    if (s1.b[1] != 30) return 13;

    struct StructArray s_arr[2] = {
        { 1, {2, 3, 4} },
        { 5, {6, 7, 8} }
    };
    if (s_arr[1].b[2] != 8) return 14;

    // 15: Unions mapped to Memory
    union UnionData u1;
    u1.i = 0x11223344;
    if (u1.i != 0x11223344) return 15;

    // 16-19: Unaligned Memory Access (CPU memory controller testing)
    char u_buf[32] = {0};
    unsigned short *us_p = (unsigned short *)(u_buf + 1);
    *us_p = 0xABCD;
    if (*us_p != 0xABCD) return 16;

    unsigned int *ui_p = (unsigned int *)(u_buf + 3);
    *ui_p = 0xDEADBEEF;
    if (*ui_p != 0xDEADBEEF) return 17;

    short *f_p = (short *)(u_buf + 5);
    *f_p = 3141;
    if (*f_p != 3141) return 18;

    // 20-23: Pointer Post/Pre Increment/Decrement Logic
    int ptr_arr[5] = {10, 20, 30, 40, 50};
    int *pt = ptr_arr;
    if (*pt++ != 10) return 20; 
    if (*++pt != 30) return 21; 
    if (++*pt != 31) return 22; 
    if ((*pt)++ != 31) return 23; 
    if (*pt != 32) return 24;   

    // 25-27: Function Parameters (Decay, Multi-dimensional, Static)
    if (sum_array(arr1, 4) != 10) return 25;
    if (process_matrix(mat, 2) != 21) return 26;
    if (process_static(arr1) != 6) return 27;

    // 28-30: Function Pointers within Arrays and Structs
    OpFunc func_arr[2] = { op_add, op_sub };
    if (func_arr[0](5, 3) != 8) return 28;
    if (func_arr[1](5, 3) != 2) return 29;

    struct FuncStruct fs = { op_add, {15, 25} };
    if (fs.op(fs.arr[0], fs.arr[1]) != 40) return 30;

    // 31-32: C99 Compound Literals
    // int *c_arr = (int[3]){ 100, 200, 300 };
    // if (c_arr[2] != 300) return 31;

    // struct StructArray *c_struct = &(struct StructArray){ 7, {8, 9, 10} };
    // if (c_struct->b[0] != 8) return 32;

    // 33-34: 3D Arrays and Pointer Math Equivalency
    int mat3d[2][2][2] = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };
    if (mat3d[1][0][1] != 6) return 33;
    int (*p3d)[2][2] = mat3d;
    if (p3d[1][1][0] != 7) return 34;

    // 35-37: Loop Interactions with Arrays
    int l_sum = 0, l_idx = 0;
    while(l_idx < 4) { l_sum += arr1[l_idx]; l_idx++; }
    if (l_sum != 10) return 35;

    l_sum = 0; l_idx = 0;
    do { l_sum += arr1[l_idx]; l_idx++; } while(l_idx < 4);
    if (l_sum != 10) return 36;

    int bc_sum = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 1) continue;
        if (i == 4) break;
        bc_sum += ptr_arr[i]; 
    }
    if (bc_sum != 82) return 37;

    // 38: Struct Overlay
    // union ArrayOverlay fu = { .fixed = { 4, {10, 20, 30, 40} } };
    // if (fu.flex.data[3] != 40) return 38;

    // 39-40: String Literals and Char Arrays
    char str[5] = "test";
    if (str[0] != 't' || str[4] != '\0') return 39;
    char *str_ptr = "cpu";
    if (str_ptr[2] != 'u') return 40;

    // 41: Contiguous Memory Guarantees
    int m_contig[2][2] = {{10, 20}, {30, 40}};
    int *p_contig = &m_contig[0][0];
    if (p_contig[3] != 40) return 41;

    // 42-43: Volatile and Const Attributes
    volatile int v_arr[2] = {77, 88};
    if (v_arr[1] != 88) return 42;
    const int c_arr[2] = {99, 111};
    if (c_arr[0] != 99) return 43;

    // 44: C99 Restrict Pointers
    // int r_src[3] = {1, 2, 3};
    // int r_dst[3] = {0, 0, 0};
    // int * restrict r1 = r_src;
    // int * restrict r2 = r_dst;
    // r2[1] = r1[1];
    // if (r2[1] != 2) return 44;

    // 45-46: Bitfield Layouts in Structs
    // struct BitFieldLayout bf = { 5, 12, 0xFF00FF };
    // if (bf.a != 5) return 45;
    // if (bf.c != 0xFF00FF) return 46;

    // 47-48: Pointer Subtraction and Comparison
    if (&ptr_arr[4] - &ptr_arr[1] != 3) return 47;
    if (&ptr_arr[2] >= &ptr_arr[3]) return 48;

    // 49-50: Array of Unions
    union ArrayUnion au[2];
    au[0].i = 0x3F800000;
    au[1].f = 25;
    if (au[0].i != 0x3F800000) return 49;
    if (au[1].f != 25) return 50;

    // 51: Negative Array Indices (from offset pointer)
    int *neg_p = &ptr_arr[3];
    if (neg_p[-2] != 20) return 51;

    // --- Conditional Tests via Macros ---

#ifdef TEST_LONG
    long l_arr[3] = { 100000L, 200000L, 300000L };
    if (l_arr[1] != 200000L) return 52;
    long *l_ptr = l_arr;
    if (*(l_ptr + 2) != 300000L) return 53;
#endif

#ifdef TEST_LONG_LONG
    long long ll_arr[3] = { 1000000000000LL, 2000000000000LL, 3000000000000LL };
    if (ll_arr[0] != 1000000000000LL) return 54;
    long long *ll_ptr = ll_arr;
    if (ll_ptr[2] != 3000000000000LL) return 55;
#endif

    return 0;
}