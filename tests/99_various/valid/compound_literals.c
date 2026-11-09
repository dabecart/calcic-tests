/*
 * compound_literals_test.c
 *
 * Exhaustive test of C99 compound literals (6.5.2.5) and their interaction with the rest of the
 * language. No standard library, no long long, no VLAs.
 *
 * Exit code:
 *   0        -> everything passed.
 *   N (1-47) -> test number N failed (see the main() table at the bottom).
 * The index of the failing check inside the test is stored in the global g_failedCheck, so it can
 * be inspected with a debugger. Each test function returns 0 on success or the (1-based) index of
 * the first failing check.
 */

int g_failedCheck = 0;

/* ------------------------------------------------------------------------------------------- */
/* Types                                                                                       */
/* ------------------------------------------------------------------------------------------- */

struct Point { int x; int y; };
struct Rect  { struct Point tl; struct Point br; };
struct Mixed { char c; int i; short s; };
struct WithArr { int id; int vals[3]; };
struct Holder { int *p; int n; };
struct Vec { double x; double y; float w; };
struct Node { int v; struct Node *next; };
struct Flags { unsigned int a : 3; unsigned int b : 5; int c : 4; };
struct Ops { int (*fn)(int); int k; };

union Num { int i; char bytes[4]; };
union Val { int i; double d; };

enum Color { RED, GREEN = 5, BLUE };
struct Painted { enum Color color; int weight; };

typedef struct Point Pt;
typedef int Triple[3];
typedef struct { int a; int b; } Pair;

/* ------------------------------------------------------------------------------------------- */
/* File scope objects (static storage duration compound literals)                              */
/* ------------------------------------------------------------------------------------------- */

int *g_ptr = (int[]){1, 2, 3};
const int *g_cptr = (const int[]){4, 5, 6};
struct Point *g_pp = &(struct Point){10, 20};
int g_size = sizeof((int[]){1, 2, 3});
struct Node *g_list = &(struct Node){1, &(struct Node){2, 0}};

/* ------------------------------------------------------------------------------------------- */
/* Helper functions                                                                            */
/* ------------------------------------------------------------------------------------------- */

static int twice(int v) { return v * 2; }

static int sumPoint(struct Point p) { return p.x + p.y; }

static int sumArr(const int *a, int n) {
    int s = 0;
    int i;
    for (i = 0; i < n; i++) s += a[i];
    return s;
}

static struct Point makePoint(int x, int y) { return (struct Point){x, y}; }

static struct WithArr makeWithArr(void) { return (struct WithArr){1, {2, 3, 4}}; }

static void setPoint(struct Point *p, int x, int y) { p->x = x; p->y = y; }

static int bump(struct Point *p) { p->x++; p->y++; return p->x + p->y; }

static int fact(int n) {
    int *p;
    int r;
    if (n <= 1) return 1;
    /* Every active frame must own its literal. */
    p = (int[]){n};
    r = fact(n - 1);
    return p[0] * r;
}

static int freshEachCall(void) {
    int *p = (int[]){0};
    (*p)++;
    return *p;
}

static int persistentEachCall(void) {
    static int s = 0;
    s++;
    return s;
}

/* ------------------------------------------------------------------------------------------- */
/* 1-4: scalar compound literals                                                               */
/* ------------------------------------------------------------------------------------------- */

static int t01_scalarInt(void) {
    int a = (int){42};
    int b = (int){a + 1};
    int c = (int){7,};              /* Trailing comma. */
    if (a != 42) return 1;
    if (b != 43) return 2;
    if (c != 7) return 3;
    if ((int){5} + (int){6} != 11) return 4;
    if ((int){3} * (int){4} != 12) return 5;
    return 0;
}

static int t02_scalarTypes(void) {
    int big = 300;
    int v = 70000;
    if ((char){65} != 65) return 1;
    if ((short){-5} != -5) return 2;
    if ((unsigned char){big} != 44) return 3;           /* 300 mod 256 */
    if ((unsigned short){v} != 4464) return 4;          /* 70000 mod 65536 */
    if ((unsigned int){4000000000u} != 4000000000u) return 5;
    if ((long){100000} != 100000) return 6;
    if ((double){1.5} != 1.5) return 7;
    if ((float){2.5} != 2.5) return 8;
    if ((long){1000000} * 1000000 != 1000000000000) return 9;
    return 0;
}

static int t03_scalarPointer(void) {
    int x = 9;
    int *p = (int *){&x};
    if (*p != 9) return 1;
    *p = 11;
    if (x != 11) return 2;
    if ((int *){0} != 0) return 3;
    if ((char *){0} != 0) return 4;
    return 0;
}

static int t04_scalarCommaAndConst(void) {
    int a = 0;
    int r = (int){(a = 3, a + 1)};      /* Comma inside parentheses is allowed. */
    const int c = (const int){5};
    if (r != 4) return 1;
    if (a != 3) return 2;
    if (c != 5) return 3;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 5-8: structs                                                                                */
/* ------------------------------------------------------------------------------------------- */

static int t05_structPositional(void) {
    struct Point p = (struct Point){3, 4};
    if (p.x != 3) return 1;
    if (p.y != 4) return 2;
    if ((struct Point){5, 6}.y != 6) return 3;
    if ((struct Point){5, 6}.x != 5) return 4;
    return 0;
}

static int t06_structDesignated(void) {
    struct Point p = (struct Point){.y = 8, .x = 7};
    struct Point q = (struct Point){.y = 2};
    struct Point r = (struct Point){1, .y = 9};
    if (p.x != 7 || p.y != 8) return 1;
    if (q.x != 0 || q.y != 2) return 2;         /* Unspecified members are zeroed. */
    if (r.x != 1 || r.y != 9) return 3;
    return 0;
}

static int t07_structPaddingAndZeroFill(void) {
    struct Mixed a = (struct Mixed){1};
    struct Mixed b = (struct Mixed){.c = 'a', .s = 7};
    struct Mixed c = (struct Mixed){'x', 100000, -3};
    if (a.c != 1 || a.i != 0 || a.s != 0) return 1;
    if (b.c != 'a' || b.i != 0 || b.s != 7) return 2;
    if (c.c != 'x' || c.i != 100000 || c.s != -3) return 3;
    return 0;
}

static int t08_structNested(void) {
    struct Rect a = (struct Rect){(struct Point){1, 2}, (struct Point){3, 4}};
    struct Rect b = (struct Rect){{5, 6}, {7, 8}};
    struct Rect c = (struct Rect){.br = (struct Point){9, 10}};
    struct Rect d = (struct Rect){.br = {.y = 3}};
    if (a.tl.x != 1 || a.tl.y != 2 || a.br.x != 3 || a.br.y != 4) return 1;
    if (b.tl.x != 5 || b.tl.y != 6 || b.br.x != 7 || b.br.y != 8) return 2;
    if (c.tl.x != 0 || c.tl.y != 0 || c.br.x != 9 || c.br.y != 10) return 3;
    if (d.br.x != 0 || d.br.y != 3 || d.tl.x != 0) return 4;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 9-14: arrays                                                                                */
/* ------------------------------------------------------------------------------------------- */

static int t09_arrayFixedSize(void) {
    int *p = (int[5]){1, 2};
    if (p[0] != 1 || p[1] != 2) return 1;
    if (p[2] != 0 || p[3] != 0 || p[4] != 0) return 2;     /* Zero fill. */
    if (sizeof((int[5]){1, 2}) != 5 * sizeof(int)) return 3;
    if ((int[5]){1, 2}[4] != 0) return 4;
    return 0;
}

static int t10_arrayUndimensioned(void) {
    if (sizeof((int[]){1, 2, 3, 4}) != 4 * sizeof(int)) return 1;
    if (sizeof((char[]){'a', 'b', 'c'}) != 3) return 2;
    if (sizeof((struct Point[]){{1, 2}, {3, 4}, {5, 6}}) != 3 * sizeof(struct Point)) return 3;
    if ((int[]){10, 20, 30}[2] != 30) return 4;
    return 0;
}

static int t11_arrayDesignated(void) {
    int *a = (int[]){[2] = 5, [0] = 1};
    int *b = (int[]){[1] = 10, 20, 30};
    int *c = (int[16]){[15] = 1};
    int i, sum = 0;
    if (sizeof((int[]){[2] = 5, [0] = 1}) != 3 * sizeof(int)) return 1;
    if (a[0] != 1 || a[1] != 0 || a[2] != 5) return 2;
    if (sizeof((int[]){[1] = 10, 20, 30}) != 4 * sizeof(int)) return 3;
    if (b[0] != 0 || b[1] != 10 || b[2] != 20 || b[3] != 30) return 4;
    for (i = 0; i < 16; i++) sum += c[i];
    if (sum != 1 || c[15] != 1) return 5;
    return 0;
}

static int t12_charArrayFromString(void) {
    char *s = (char[]){"abc"};
    char *t = (char[8]){"hi"};
    int i;
    if (sizeof((char[]){"hello"}) != 6) return 1;
    if (s[0] != 'a' || s[1] != 'b' || s[2] != 'c' || s[3] != 0) return 2;
    s[0] = 'z';                                          /* Literals are modifiable. */
    if (s[0] != 'z') return 3;
    if (t[0] != 'h' || t[1] != 'i') return 4;
    for (i = 2; i < 8; i++) if (t[i] != 0) return 5;
    return 0;
}

static int t13_multiDimensional(void) {
    if ((int[2][2]){{1, 2}, {3, 4}}[1][0] != 3) return 1;
    if ((int[2][2]){{1, 2}, {3, 4}}[0][1] != 2) return 2;
    if (sizeof((int[2][2]){{1, 2}, {3, 4}}) != 4 * sizeof(int)) return 3;
    if (sizeof((int[][2]){{1, 2}, {3, 4}, {5, 6}}) != 6 * sizeof(int)) return 4;
    if ((int[][2]){{1, 2}, {3, 4}, {5, 6}}[2][1] != 6) return 5;
    return 0;
}

static int t14_arrayOfStructsAndStructWithArray(void) {
    struct Point *pts = (struct Point[]){{1, 2}, {3, 4}, {5, 6}};
    struct Point *sparse = (struct Point[2]){[1] = {7, 8}};
    struct WithArr w = (struct WithArr){7, {1, 2, 3}};
    if (pts[0].x != 1 || pts[1].y != 4 || pts[2].y != 6) return 1;
    if (sparse[0].x != 0 || sparse[0].y != 0 || sparse[1].x != 7 || sparse[1].y != 8) return 2;
    if (w.id != 7 || w.vals[0] != 1 || w.vals[2] != 3) return 3;
    if ((struct WithArr){.vals = {4, 5}}.vals[1] != 5) return 4;
    if ((struct WithArr){.vals = {4, 5}}.vals[2] != 0) return 5;
    if ((struct WithArr){.vals = {4, 5}}.id != 0) return 6;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 15-17: unions                                                                               */
/* ------------------------------------------------------------------------------------------- */

static int t15_unionFirstMember(void) {
    if ((union Num){5}.i != 5) return 1;
    if ((union Val){3}.i != 3) return 2;
    return 0;
}

static int t16_unionDesignated(void) {
    union Val v = (union Val){.d = 2.5};
    union Num n = (union Num){.i = 0x01020304};
    if (v.d != 2.5) return 1;
    if (n.i != 0x01020304) return 2;
    if ((union Val){.i = -9}.i != -9) return 3;
    if (sizeof((union Val){.d = 1.0}) != sizeof(union Val)) return 4;
    return 0;
}

static int t17_bitfields(void) {
    struct Flags f = (struct Flags){5, 17, -3};
    struct Flags *fp;
    if (f.a != 5 || f.b != 17 || f.c != -3) return 1;
    if ((struct Flags){.b = 31}.b != 31) return 2;
    if ((struct Flags){.b = 31}.a != 0) return 3;
    fp = &(struct Flags){1, 2, 3};
    fp->b = 20;
    if (fp->a != 1 || fp->b != 20 || fp->c != 3) return 4;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 18-22: lvalue behaviour, address-of, pointer arithmetic                                     */
/* ------------------------------------------------------------------------------------------- */

static int t18_structIsModifiableLvalue(void) {
    struct Point *p = &(struct Point){1, 2};
    int r;
    p->x = 10;
    p->y += 5;
    if (p->x != 10 || p->y != 7) return 1;
    r = ((struct Point){1, 2}.x = 5);
    if (r != 5) return 2;
    r = ((struct Point){1, 2}.x += 5);
    if (r != 6) return 3;
    return 0;
}

static int t19_arrayIsModifiableLvalue(void) {
    int *a = (int[]){1, 2, 3};
    int r;
    a[1] = 20;
    a[2]++;
    a[0] += a[1];
    if (a[0] != 21 || a[1] != 20 || a[2] != 4) return 1;
    r = (int[]){1, 2}[0]++;
    if (r != 1) return 2;
    r = ++(int){5};
    if (r != 6) return 3;
    return 0;
}

static int t20_addressOfAndDereference(void) {
    if (*(int[]){7, 8} != 7) return 1;
    if (*&(int){3} != 3) return 2;
    if (*((int[]){7, 8} + 1) != 8) return 3;
    if ((&(struct Point){3, 4})->y != 4) return 4;
    if ((*&(struct Point){3, 4}).x != 3) return 5;
    return 0;
}

static int t21_pointerArithmetic(void) {
    int *b = (int[]){10, 20, 30, 40};
    int *e = b + 4;
    if (e - b != 4) return 1;
    if (*(e - 1) != 40) return 2;
    if (*(b + 2) != 30) return 3;
    b++;
    if (*b != 20) return 4;
    if (2[(int[]){5, 6, 7}] != 7) return 5;         /* Index and pointer swapped. */
    return 0;
}

static int t22_literalAsSubscriptIndex(void) {
    int arr[4];
    arr[0] = 100; arr[1] = 101; arr[2] = 102; arr[3] = 103;
    if (arr[(int[]){2}[0]] != 102) return 1;
    if (arr[(struct Point){1, 3}.y] != 103) return 2;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 23-27: function interaction                                                                 */
/* ------------------------------------------------------------------------------------------- */

static int t23_passStructByValue(void) {
    if (sumPoint((struct Point){3, 4}) != 7) return 1;
    if (sumPoint((struct Point){sumPoint((struct Point){1, 2}), 4}) != 7) return 2;
    return 0;
}

static int t24_passArrayAndPointer(void) {
    struct Point p = {1, 1};
    if (sumArr((int[]){1, 2, 3, 4}, 4) != 10) return 1;
    if (sumArr((const int[]){5, 5}, 2) != 10) return 2;
    if (bump(&(struct Point){1, 2}) != 5) return 3;
    setPoint(&p, 8, 9);
    if (p.x != 8 || p.y != 9) return 4;
    setPoint(&(struct Point){0, 0}, 1, 2);          /* Must at least compile and run. */
    return 0;
}

static int t25_returnStructBuiltFromLiteral(void) {
    struct Point q = makePoint(5, 6);
    struct WithArr w = makeWithArr();
    if (q.x != 5 || q.y != 6) return 1;
    if (makePoint(1, 2).y != 2) return 2;
    if (w.id != 1 || w.vals[0] != 2 || w.vals[1] != 3 || w.vals[2] != 4) return 3;
    return 0;
}

static int t26_recursionAndFreshObjects(void) {
    if (fact(5) != 120) return 1;
    if (fact(1) != 1) return 2;
    if (freshEachCall() != 1) return 3;
    if (freshEachCall() != 1) return 4;             /* Re-initialized on each call. */
    if (persistentEachCall() != 1) return 5;
    if (persistentEachCall() != 2) return 6;        /* Control: static local keeps its value. */
    return 0;
}

static int t27_functionPointerMember(void) {
    struct Ops o = (struct Ops){.fn = twice, .k = 3};
    if ((struct Ops){twice, 3}.fn(4) != 8) return 1;
    if (o.fn(o.k) != 6) return 2;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 28-31: lifetime, loops and scopes                                                           */
/* ------------------------------------------------------------------------------------------- */

static int t28_loopsReinitializeLiteral(void) {
    int i, total = 0, total2 = 0, total3 = 0, k = 0;
    for (i = 0; i < 5; i++) {
        struct Point p = (struct Point){i, i * 2};
        total += p.x + p.y;
    }
    if (total != 30) return 1;                      /* 3 * (0+1+2+3+4) */
    while (k < 3) {
        int *q = (int[]){k, k + 1};
        total2 += q[0] + q[1];
        k++;
    }
    if (total2 != 9) return 2;                      /* 1 + 3 + 5 */
    for (i = 0; i < 3; i++) {
        int *c = (int[]){0};                        /* Fresh zero on every iteration. */
        *c += 1;
        total3 += *c;
    }
    if (total3 != 3) return 3;
    return 0;
}

static int t29_literalInControlConditions(void) {
    int n = 3, cnt = 0, r = 0;
    while ((int){n}) { n--; cnt++; }
    if (cnt != 3) return 1;
    if ((struct Point){0, 1}.y) r = 1; else r = 2;
    if (r != 1) return 2;
    switch ((struct Point){3, 0}.x) {
        case 3: r = 10; break;
        default: r = 20; break;
    }
    if (r != 10) return 3;
    if (!((struct Point){1, 2}.x < (struct Point){3, 4}.y && !(int){0})) return 4;
    return 0;
}

static int t30_nestedScopes(void) {
    int *outer = (int[]){1, 2};
    {
        int *inner = (int[]){3, 4};
        outer[0] += inner[1];
    }
    if (outer[0] != 5) return 1;
    return 0;
}

static int t31_fileScopeLiterals(void) {
    if (g_ptr[0] != 1 || g_ptr[1] != 2 || g_ptr[2] != 3) return 1;
    g_ptr[1] = 20;                                  /* Static storage: persists. */
    if (g_ptr[1] != 20) return 2;
    if (g_cptr[0] != 4 || g_cptr[2] != 6) return 3;
    if (g_pp->x != 10 || g_pp->y != 20) return 4;
    g_pp->y = 21;
    if (g_pp->y != 21) return 5;
    if (g_size != 3 * (int)sizeof(int)) return 6;
    if (g_list->v != 1) return 7;
    if (g_list->next->v != 2) return 8;
    if (g_list->next->next != 0) return 9;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 32-36: expressions, casts and qualifiers                                                    */
/* ------------------------------------------------------------------------------------------- */

static int t32_runtimeInitializers(void) {
    int a = 3, b = 4;
    struct Point p = (struct Point){a * b, a + b};
    if (p.x != 12 || p.y != 7) return 1;
    if ((int[]){a, b, a + b}[2] != 7) return 2;
    if ((struct Point){twice(a), twice(b)}.y != 8) return 3;
    return 0;
}

static int t33_castVersusLiteral(void) {
    int x = 5;
    if ((int)x != 5) return 1;
    if ((int)(char){65} != 65) return 2;
    if ((int)(double){3.9} != 3) return 3;
    if ((long)(int){x} != 5) return 4;
    if (((char){66}) != 66) return 5;
    return 0;
}

static int t34_constQualified(void) {
    const struct Point *cp = &(const struct Point){1, 2};
    const int *ci = (const int[]){9, 8};
    if (cp->x + cp->y != 3) return 1;
    if (ci[0] != 9 || ci[1] != 8) return 2;
    if ((const int){5} != 5) return 3;
    return 0;
}

static int t35_sizeof(void) {
    if (sizeof((struct Point){1, 2}) != sizeof(struct Point)) return 1;
    if (sizeof((int[3]){0}) != 3 * sizeof(int)) return 2;
    if (sizeof((struct Mixed){1}) != sizeof(struct Mixed)) return 3;
    if (sizeof((char){1}) != 1) return 4;
    if (sizeof((struct Rect){{1, 2}, {3, 4}}) != 2 * sizeof(struct Point)) return 5;
    return 0;
}

static int t36_ternaryWithLiterals(void) {
    int c = 1, d = 0;
    if ((c ? &(struct Point){1, 2} : &(struct Point){3, 4})->x != 1) return 1;
    if ((d ? &(struct Point){1, 2} : &(struct Point){3, 4})->x != 3) return 2;
    if ((c ? (int[]){1, 2} : (int[]){3, 4})[1] != 2) return 3;
    if ((d ? (int[]){1, 2} : (int[]){3, 4})[1] != 4) return 4;
    if ((c ? (int){10} : (int){20}) != 10) return 5;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* 37-47: composition with other language features                                             */
/* ------------------------------------------------------------------------------------------- */

static int t37_assignmentFromLiteral(void) {
    struct Point a;
    struct Point b = {0, 0};
    struct Point *p = &b;
    a = (struct Point){5, 6};
    if (a.x != 5 || a.y != 6) return 1;
    *p = (struct Point){7, 8};
    if (b.x != 7 || b.y != 8) return 2;
    a = (struct Point){.y = 1};
    if (a.x != 0 || a.y != 1) return 3;
    return 0;
}

static int t38_literalsPointingToLiterals(void) {
    struct Holder h = (struct Holder){(int[]){1, 2, 3}, 3};
    struct Node *l = &(struct Node){1, &(struct Node){2, 0}};
    if (sumArr(h.p, h.n) != 6) return 1;
    if (l->v != 1 || l->next->v != 2 || l->next->next != 0) return 2;
    return 0;
}

static int t39_arrayOfStrings(void) {
    const char **names = (const char *[]){"ab", "cde"};
    if (names[0][0] != 'a' || names[0][1] != 'b' || names[0][2] != 0) return 1;
    if (names[1][2] != 'e') return 2;
    if (sizeof((const char *[]){"x", "y", "z"}) != 3 * sizeof(const char *)) return 3;
    return 0;
}

static int t40_enums(void) {
    struct Painted p = (struct Painted){BLUE, 4};
    if ((enum Color){GREEN} != 5) return 1;
    if ((enum Color){BLUE} != BLUE) return 2;
    if (p.color != 6 || p.weight != 4) return 3;
    if ((struct Painted){.weight = 2}.color != RED) return 4;
    return 0;
}

static int t41_floatingPoint(void) {
    struct Vec v = (struct Vec){1.5, 2.5, 0.5};
    if (v.x + v.y != 4.0) return 1;
    if (v.w * 2 != 1.0) return 2;
    if ((struct Vec){1, 2}.x != 1.0) return 3;          /* int -> double conversion. */
    if ((struct Vec){.y = 3.25}.y != 3.25) return 4;
    if ((struct Vec){.y = 3.25}.x != 0.0) return 5;
    return 0;
}

static int t42_typedefs(void) {
    if ((Pt){1, 2}.y != 2) return 1;
    if ((Triple){1, 2, 3}[2] != 3) return 2;
    if (sizeof((Triple){0}) != 3 * sizeof(int)) return 3;
    if ((Pair){4, 5}.b != 5) return 4;
    if ((Pair){.b = 7}.a != 0) return 5;
    return 0;
}

static int t43_independentObjects(void) {
    /* Two textually identical literals are two distinct objects. */
    struct Point *a = &(struct Point){1, 2};
    struct Point *b = &(struct Point){1, 2};
    a->x = 100;
    if (b->x != 1) return 1;
    if (a == b) return 2;
    b->x = 7;
    if (a->x != 100) return 3;
    return 0;
}

static int t44_copyingLiteralIsByValue(void) {
    struct Point src = (struct Point){1, 2};
    struct Point dst = src;
    struct Point *lit = &(struct Point){3, 4};
    struct Point copy = *lit;
    dst.x = 50;
    lit->x = 60;
    if (src.x != 1) return 1;
    if (copy.x != 3) return 2;
    if (lit->x != 60) return 3;
    return 0;
}

static int t45_compoundOperationsOnMembers(void) {
    struct Point *p = &(struct Point){10, 20};
    p->x -= 3;
    p->y *= 2;
    p->x <<= 1;
    p->y |= 1;
    if (p->x != 14) return 1;
    if (p->y != 41) return 2;
    p->x = p->x % 5;
    if (p->x != 4) return 3;
    return 0;
}

static int t46_literalOfLiteralMembers(void) {
    struct Rect r = (struct Rect){(struct Point){1, 2}, (struct Point){3, 4}};
    struct Rect copy = (struct Rect){r.tl, r.br};
    struct Point swapped = (struct Point){r.tl.y, r.tl.x};
    if (copy.tl.x != 1 || copy.br.y != 4) return 1;
    if (swapped.x != 2 || swapped.y != 1) return 2;
    if ((struct Rect){r.br, r.tl}.tl.x != 3) return 3;
    return 0;
}

static int t47_manyLiteralsInOneExpression(void) {
    int r = (struct Point){1, 2}.x + (struct Point){3, 4}.y + (int[]){5, 6}[1] + (int){7};
    if (r != 1 + 4 + 6 + 7) return 1;
    r = sumPoint((struct Point){(int[]){1, 2}[1], (int){3}}) + sumArr((int[]){1, 1}, 2);
    if (r != 5 + 2) return 2;
    return 0;
}

/* ------------------------------------------------------------------------------------------- */
/* Driver                                                                                      */
/* ------------------------------------------------------------------------------------------- */

static int fail(int testId, int check) {
    g_failedCheck = check;
    return testId;
}

int main(void) {
    int r;

    r = t01_scalarInt();                             if (r) return fail(1, r);
    r = t02_scalarTypes();                           if (r) return fail(2, r);
    r = t03_scalarPointer();                         if (r) return fail(3, r);
    r = t04_scalarCommaAndConst();                   if (r) return fail(4, r);
    r = t05_structPositional();                      if (r) return fail(5, r);
    r = t06_structDesignated();                      if (r) return fail(6, r);
    r = t07_structPaddingAndZeroFill();              if (r) return fail(7, r);
    r = t08_structNested();                          if (r) return fail(8, r);
    r = t09_arrayFixedSize();                        if (r) return fail(9, r);
    r = t10_arrayUndimensioned();                    if (r) return fail(10, r);
    r = t11_arrayDesignated();                       if (r) return fail(11, r);
    r = t12_charArrayFromString();                   if (r) return fail(12, r);
    r = t13_multiDimensional();                      if (r) return fail(13, r);
    r = t14_arrayOfStructsAndStructWithArray();      if (r) return fail(14, r);
    r = t15_unionFirstMember();                      if (r) return fail(15, r);
    r = t16_unionDesignated();                       if (r) return fail(16, r);
    r = t17_bitfields();                             if (r) return fail(17, r);
    r = t18_structIsModifiableLvalue();              if (r) return fail(18, r);
    r = t19_arrayIsModifiableLvalue();               if (r) return fail(19, r);
    r = t20_addressOfAndDereference();               if (r) return fail(20, r);
    r = t21_pointerArithmetic();                     if (r) return fail(21, r);
    r = t22_literalAsSubscriptIndex();               if (r) return fail(22, r);
    r = t23_passStructByValue();                     if (r) return fail(23, r);
    r = t24_passArrayAndPointer();                   if (r) return fail(24, r);
    r = t25_returnStructBuiltFromLiteral();          if (r) return fail(25, r);
    r = t26_recursionAndFreshObjects();              if (r) return fail(26, r);
    r = t27_functionPointerMember();                 if (r) return fail(27, r);
    r = t28_loopsReinitializeLiteral();              if (r) return fail(28, r);
    r = t29_literalInControlConditions();            if (r) return fail(29, r);
    r = t30_nestedScopes();                          if (r) return fail(30, r);
    r = t31_fileScopeLiterals();                     if (r) return fail(31, r);
    r = t32_runtimeInitializers();                   if (r) return fail(32, r);
    r = t33_castVersusLiteral();                     if (r) return fail(33, r);
    r = t34_constQualified();                        if (r) return fail(34, r);
    r = t35_sizeof();                                if (r) return fail(35, r);
    r = t36_ternaryWithLiterals();                   if (r) return fail(36, r);
    r = t37_assignmentFromLiteral();                 if (r) return fail(37, r);
    r = t38_literalsPointingToLiterals();            if (r) return fail(38, r);
    r = t39_arrayOfStrings();                        if (r) return fail(39, r);
    r = t40_enums();                                 if (r) return fail(40, r);
    r = t41_floatingPoint();                         if (r) return fail(41, r);
    r = t42_typedefs();                              if (r) return fail(42, r);
    r = t43_independentObjects();                    if (r) return fail(43, r);
    r = t44_copyingLiteralIsByValue();               if (r) return fail(44, r);
    r = t45_compoundOperationsOnMembers();           if (r) return fail(45, r);
    r = t46_literalOfLiteralMembers();               if (r) return fail(46, r);
    r = t47_manyLiteralsInOneExpression();           if (r) return fail(47, r);

    return 0;
}