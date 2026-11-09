/*
- unsized_arrays.c - Thorough test of C99 arrays declared without an
- explicit (first-dimension) size: int a[] = {...}, int m[][3] = {...},
- char s[] = "...", extern int e[], function parameters int a[] / int m[][3],
- typedefs of incomplete array types, compound literals, designators, ...
 *
- Out of scope: flexible array members, VLAs, long long, standard library.
 *
- Exit status:
-   0      -> every check passed
-   N != 0 -> a check inside test number N failed (see tNN_ functions; the
-             number is also stored in the enum constant T of each test).
 *
- Single translation unit: "extern" is exercised by declaring arrays extern
- with incomplete type, using them, and defining/completing them later in
- the same file (including block-scope extern declarations).
 *
- Expect warnings such as "missing braces" or "assumed to have one element"
- from some compilers; they are intentional.
 */

/* Define BRACKET_ELISION to use bracket elision lines; undefine or comment out to run without bracket elision */
// #define BRACKET_ELISION

#define CHECK(...) do { if (!(__VA_ARGS__)) return T; } while (0)
#define SZ(...)    ((int)sizeof(__VA_ARGS__))
#define COUNT(...) (sizeof(__VA_ARGS__) / sizeof((__VA_ARGS__)[0]))

struct pt { int x, y; };
enum { EA, EB, EC };
enum { COLS = 4 };

typedef int  Arr[];
typedef int  M3[][3];
typedef char Str[];
typedef int  Row3[3];

/* ------------------------------------------------------------------ */
/* File-scope declarations with incomplete array types                */
/* ------------------------------------------------------------------ */

extern int  g_ext1[];
extern int  g_ext2[][3];
extern char g_ext_str[];
extern int  g_ext3[];
extern int  g_ext3[4];            /* redeclaration completes the type  */
extern int  g_ext4[][2];
extern int  g_ext4[3][2];         /* completes the first dimension     */
extern struct pt g_ext_pts[];

int g_tent[];                     /* tentative definition: 1 element at
                                     end of the translation unit       */

/* uses of the incomplete externs *before* their definition
   (indexing is fine, sizeof would not be) */
static int use_ext_before(void)
{
    return g_ext1[1] + g_ext2[1][2] + g_ext_str[0];   /* 20 + 6 + 'h' */
}

static int block_extern_before(void)
{
    extern int g_late[];
    extern int g_late2[][2];
    return g_late[2] * 100 + g_late2[1][1];           /* 900 + 4 */
}

/* definitions */
int g_ext1[] = { 10, 20, 30 };
int g_ext2[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
char g_ext_str[] = "hello";
int g_ext3[4] = { 1, 2, 3, 4 };
int g_ext4[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
struct pt g_ext_pts[] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
int g_late[] = { 7, 8, 9 };
int g_late2[][2] = { { 1, 2 }, { 3, 4 } };

/* internal-linkage globals */
static int  g_tbl[] = { 5, 10, 15, 20 };
static int  g_copy[sizeof(g_tbl) / sizeof(g_tbl[0])];  /* constant dim */
static const char g_msg[] = "global";
static char g_names[][6] = { "one", "two", "three", "four" };
static int  g_des[] = { [4] = 1, 2 };
static int  g_a1[] = { 1, 2 }, g_a2[] = { 3, 4, 5 };
static int *g_ptrs[] = { g_a1, g_a2, &g_tbl[1] };
static int  g_m[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

struct Tbl { int n; const int *d; };
static struct Tbl g_tb = { sizeof(g_tbl) / sizeof(g_tbl[0]), g_tbl };

/* ------------------------------------------------------------------ */
/* Helpers (parameters of incomplete array type)                      */
/* ------------------------------------------------------------------ */

static int g_count;
static int next(void)        { return ++g_count; }
static int twice(int x)      { return x * 2; }
static int neg(int x)        { return -x; }

/* prototype with [] and definition with * : compatible */
static int sum(int a[], int n);
static int sum(int *a, int n)
{
    int s = 0, i;
    for (i = 0; i < n; i++)
        s += a[i];
    return s;
}

static int sum2(int m[][3], int rows)
{
    int s = 0, i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < 3; j++)
            s += m[i][j];
    return s;
}

static int sum2p(int (*m)[3], int rows) { return sum2(m, rows); }
static int sum2f(int m[2][3])           { return m[0][0] + m[1][2]; }

static int sum3(int t[][2][2], int n)
{
    int s = 0, i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                s += t[i][j][k];
    return s;
}

static int slen(const char s[])
{
    int n = 0;
    while (s[n])
        n++;
    return n;
}

static int streq(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return *a == *b;
}

static int names_total(char n[][4], int cnt)
{
    int t = 0, i;
    for (i = 0; i < cnt; i++)
        t += slen(n[i]);
    return t;
}

static int param_sz1(int a[])       { return (int)sizeof(a); }
static int param_sz10(int a[10])    { return (int)sizeof(a); }
static int param_sz2(int m[][3])    { return (int)sizeof(m); }
static int param_sz_row(int m[][3]) { return (int)sizeof(m[0]); }
static int param_sz_der(int m[][3]) { return (int)sizeof(*m); }

static int first3(int a[static 3])  { return a[0] + a[1] + a[2]; }
static int const_param(int a[const], int n)
{
    a[0] = n;
    return a[0] + a[n - 1];
}

static int via_incomplete(int (*p)[]) { return (*p)[1]; }

static void fill(int a[], int n, int v)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = v;
}

static void fill2(int m[][3], int rows, int v)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < 3; j++)
            m[i][j] = v;
}

static void reverse(int a[], int n)
{
    int i, t;
    for (i = 0; i < n / 2; i++) {
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}

static void sort(int a[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

static void matmul(int a[][2], int b[][3], int c[][3], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

/* returning pointers to arrays */
static int (*row_ptr(int (*m)[3], int i))[3] { return m + i; }
static Row3 *row_ptr2(Row3 *m, int i)        { return m + i; }

static int *tbl_ptr(void)
{
    static int tbl[] = { 4, 5, 6, 7 };
    return tbl;
}

static int tbl_count(void)
{
    static int tbl[] = { 4, 5, 6, 7 };
    return (int)COUNT(tbl);
}

static int bump(void)
{
    static int c[] = { 0, 0, 0 };
    c[1]++;
    return c[1] * 10 + (int)COUNT(c);
}

/* compatible redeclarations of functions with array parameters */
static int cmp1(int m[][3]);
static int cmp1(int (*m)[3]) { return m[1][0]; }
static int cmp2(int *a);
static int cmp2(int a[])     { return a[1]; }
static int cmp3(int m[2][3]);
static int cmp3(int m[][3])  { return m[1][2]; }
static int cmp4(int a[3]);
static int cmp4(int a[10])   { return a[2]; }

struct E { const char *k; int v; };
static int lookup(const struct E t[], int n, const char *key)
{
    int i;
    for (i = 0; i < n; i++)
        if (streq(t[i].k, key))
            return t[i].v;
    return -1;
}

/* ------------------------------------------------------------------ */
/* Tests                                                              */
/* ------------------------------------------------------------------ */

/* 1: size deduced from initializer, basic types */
static int t01_basic(void)
{
    enum { T = 1 };
    int a[] = { 1, 2, 3 };
    CHECK(SZ(a) == 3 * SZ(int));
    CHECK(COUNT(a) == 3);
    CHECK(a[0] == 1 && a[1] == 2 && a[2] == 3);

    int b[] = { 1, 2, 3, };                 /* trailing comma */
    CHECK(COUNT(b) == 3);

    int c[] = { 42 };
    CHECK(COUNT(c) == 1);
    CHECK(c[0] == 42);

    int d[] = { 0 };
    CHECK(COUNT(d) == 1);

    double e[] = { 1.5, 2.5 };
    CHECK(COUNT(e) == 2);
    CHECK(SZ(e) == 2 * SZ(double));
    CHECK(e[1] == 2.5);

    char f[] = { 'a', 'b', 'c', 'd' };
    CHECK(COUNT(f) == 4);
    CHECK(SZ(f) == 4);

    short g[] = { 1, 2, 3, 4, 5 };
    CHECK(COUNT(g) == 5);
    CHECK(SZ(g) == 5 * SZ(short));

    unsigned long h[] = { 1, 2 };
    CHECK(COUNT(h) == 2);
    CHECK(SZ(h) == 2 * SZ(unsigned long));
    return 0;
}

/* 2: non-constant initializers (automatic storage) */
static int t02_nonconstant_init(void)
{
    enum { T = 2 };
    int v = 5;
    int a[] = { v, v + 1, v * 2 };
    CHECK(COUNT(a) == 3);
    CHECK(a[0] == 5 && a[1] == 6 && a[2] == 10);

    g_count = 0;
    int b[] = { next(), next() };
    CHECK(COUNT(b) == 2);
    CHECK(b[0] + b[1] == 3);        /* evaluation order unspecified */

    int *p = &v;
    int c[] = { *p, *p + 1, a[2] };
    CHECK(COUNT(c) == 3);
    CHECK(c[0] == 5 && c[1] == 6 && c[2] == 10);
    return 0;
}

/* 3: designated initializers determine the size */
static int t03_designators(void)
{
    enum { T = 3 };
    int a[] = { [2] = 1, 5 };
    CHECK(COUNT(a) == 4);
    CHECK(a[0] == 0 && a[1] == 0 && a[2] == 1 && a[3] == 5);

    int b[] = { [5] = 1 };
    CHECK(COUNT(b) == 6);
    CHECK(b[5] == 1 && b[0] == 0 && b[4] == 0);

    int c[] = { [3] = 1, 2, 3 };
    CHECK(COUNT(c) == 6);
    CHECK(c[2] == 0 && c[3] == 1 && c[4] == 2 && c[5] == 3);

    int d[] = { 1, [4] = 5, 6 };
    CHECK(COUNT(d) == 6);
    CHECK(d[0] == 1 && d[1] == 0 && d[4] == 5 && d[5] == 6);

    int e[] = { [1] = 1, 2, [0] = 3 };
    CHECK(COUNT(e) == 3);
    CHECK(e[0] == 3 && e[1] == 1 && e[2] == 2);

    int f[] = { [EA] = 10, [EB] = 20, [EC] = 30 };
    CHECK(COUNT(f) == 3);
    CHECK(f[EA] == 10 && f[EB] == 20 && f[EC] == 30);

    int g[] = { [0] = 1 };
    CHECK(COUNT(g) == 1);

    int h[] = { [1 + 2] = 3 };
    CHECK(COUNT(h) == 4);
    CHECK(h[3] == 3);
    return 0;
}

/* 4: char arrays initialised from string literals */
static int t04_strings(void)
{
    enum { T = 4 };
    char a[] = "abc";
    CHECK(SZ(a) == 4);
    CHECK(a[3] == 0);
    CHECK(slen(a) == 3);

    char b[] = "";
    CHECK(SZ(b) == 1);
    CHECK(b[0] == 0);

    char c[] = "ab" "cd";
    CHECK(SZ(c) == 5);
    CHECK(slen(c) == 4);

    char d[] = { 'a', 'b' };
    CHECK(SZ(d) == 2);

    char e[] = { "xyz" };
    CHECK(SZ(e) == 4);

    char f[] = "hello";
    f[0] = 'J';
    CHECK(slen(f) == 5);
    CHECK(f[0] == 'J');

    const char *p = "abc";
    CHECK(SZ(p) == SZ(char *));
    CHECK(SZ("abc") == 4);
    CHECK(SZ(a) != SZ(p) || SZ(char *) == 4);

    unsigned char u[] = "ab";
    CHECK(SZ(u) == 3);
    signed char sc[] = "ab";
    CHECK(SZ(sc) == 3);

    char g[] = "a\0b";
    CHECK(SZ(g) == 4);
    CHECK(g[1] == 0 && g[2] == 'b');

    char h[] = "\n\t";
    CHECK(SZ(h) == 3);
    return 0;
}

/* 5: unsized first dimension, fully braced */
static int t05_2d_braced(void)
{
    enum { T = 5 };
    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    CHECK(COUNT(m) == 3);
    CHECK(SZ(m) == 9 * SZ(int));
    CHECK(SZ(m[0]) == 3 * SZ(int));
    CHECK(COUNT(m[0]) == 3);
    CHECK(m[2][1] == 8);
    CHECK(sum2(m, 3) == 45);

    int p[][3] = { { 1 }, { 2, 3 }, { 4, 5, 6 } };
    CHECK(COUNT(p) == 3);
    CHECK(p[0][1] == 0 && p[0][2] == 0);
    CHECK(p[1][1] == 3 && p[1][2] == 0);
    CHECK(p[2][2] == 6);

    int q[][3] = { { 1, 2, 3 }, };
    CHECK(COUNT(q) == 1);

    int r[][3] = { { 0 } };
    CHECK(COUNT(r) == 1);
    CHECK(r[0][2] == 0);

    int s[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, };
    CHECK(COUNT(s) == 2);

    double d[][2] = { { 1.5, 2.5 }, { 3.5, 4.5 } };
    CHECK(COUNT(d) == 2);
    CHECK(d[1][0] == 3.5);
    CHECK(SZ(d) == 4 * SZ(double));
    return 0;
}

/* 6: unsized first dimension with brace elision */
static int t06_2d_elision(void)
{
    enum { T = 6 };
#ifdef BRACKET_ELISION
    int a[][3] = { 1, 2, 3, 4, 5 };
#else
    int a[][3] = { { 1, 2, 3 }, { 4, 5, 0 } };
#endif
    CHECK(COUNT(a) == 2);
    CHECK(a[0][2] == 3);
    CHECK(a[1][1] == 5);
    CHECK(a[1][2] == 0);

#ifdef BRACKET_ELISION
    int b[][3] = { 1, 2, 3, 4, 5, 6, 7 };
#else
    int b[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 0, 0 } };
#endif
    CHECK(COUNT(b) == 3);
    CHECK(b[2][0] == 7 && b[2][1] == 0);

#ifdef BRACKET_ELISION
    int c[][3] = { 0 };
#else
    int c[][3] = { { 0 } };
#endif
    CHECK(COUNT(c) == 1);

#ifdef BRACKET_ELISION
    int d[][3] = { { 1, 2, 3 }, 4, 5, 6 };
#else
    int d[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
#endif
    CHECK(COUNT(d) == 2);
    CHECK(d[1][0] == 4 && d[1][2] == 6);

#ifdef BRACKET_ELISION
    int e[][3] = { 1, 2, 3, 4, 5, 6 };
#else
    int e[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
#endif
    CHECK(COUNT(e) == 2);

#ifdef BRACKET_ELISION
    int f[][3] = { { 1 }, 2, 3, 4 };
#else
    int f[][3] = { { 1, 0, 0 }, { 2, 3, 4 } };
#endif
    CHECK(COUNT(f) == 2);
    CHECK(f[0][1] == 0);
    CHECK(f[1][0] == 2 && f[1][2] == 4);

#ifdef BRACKET_ELISION
    int g[][2] = { 1, 2, 3 };
#else
    int g[][2] = { { 1, 2 }, { 3, 0 } };
#endif
    CHECK(COUNT(g) == 2);
    CHECK(g[1][0] == 3 && g[1][1] == 0);
    return 0;
}

/* 7: three dimensions */
static int t07_3d(void)
{
    enum { T = 7 };
    int a[][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
    CHECK(COUNT(a) == 2);
    CHECK(SZ(a) == 8 * SZ(int));
    CHECK(SZ(a[0]) == 4 * SZ(int));
    CHECK(SZ(a[0][0]) == 2 * SZ(int));
    CHECK(a[1][1][0] == 7);
    CHECK(sum3(a, 2) == 36);

#ifdef BRACKET_ELISION
    int b[][2][2] = { 1, 2, 3, 4, 5 };
#else
    int b[][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 0 }, { 0, 0 } } };
#endif
    CHECK(COUNT(b) == 2);
    CHECK(b[0][1][1] == 4);
    CHECK(b[1][0][0] == 5);
    CHECK(b[1][0][1] == 0);

    int c[][2][2] = { { { 1 } } };
    CHECK(COUNT(c) == 1);

#ifdef BRACKET_ELISION
    int d[][2][2] = { { { 1, 2 }, { 3, 4 } }, 5, 6, 7, 8 };
#else
    int d[][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
#endif
    CHECK(COUNT(d) == 2);
    CHECK(d[1][0][0] == 5 && d[1][0][1] == 6);
    CHECK(d[1][1][0] == 7 && d[1][1][1] == 8);

#ifdef BRACKET_ELISION
    int e[][2][2] = { [2][1][1] = 9 };
#else
    int e[][2][2] = { [2] = {[1] = {[1] = 9}} };
#endif
    CHECK(COUNT(e) == 3);
    CHECK(e[2][1][1] == 9);
    CHECK(e[0][0][0] == 0);
    return 0;
}

/* 8: 2D char arrays (tables of strings) */
static int t08_char_2d(void)
{
    enum { T = 8 };
    char n[][4] = { "abc", "de", "f" };
    CHECK(COUNT(n) == 3);
    CHECK(SZ(n) == 12);
    CHECK(n[0][3] == 0);
    CHECK(n[1][1] == 'e' && n[1][2] == 0);
    CHECK(n[2][0] == 'f' && n[2][1] == 0);
    CHECK(names_total(n, 3) == 6);

    char s[][3] = { "ab", "cd", "ef" };
    CHECK(COUNT(s) == 3);
    CHECK(s[2][0] == 'e');
    CHECK(s[2][2] == 0);

    char d[][8] = { [2] = "ab", [0] = "x" };
    CHECK(COUNT(d) == 3);
    CHECK(d[0][0] == 'x');
    CHECK(d[1][0] == 0);
    CHECK(d[2][1] == 'b');

    char e[][2] = { { 'a', 'b' }, { 'c', 'd' } };
    CHECK(COUNT(e) == 2);
    CHECK(e[1][1] == 'd');

    char f[][4] = { "ab", "cd" };
    f[0][0] = 'X';
    CHECK(f[0][0] == 'X');
    CHECK(slen(f[0]) == 2);
    return 0;
}

/* 9: arrays of structs, pointers, function pointers */
static int t09_aggregates(void)
{
    enum { T = 9 };
    struct pt a[] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    CHECK(COUNT(a) == 3);
    CHECK(SZ(a) == 3 * SZ(struct pt));
    CHECK(a[2].y == 6);

#ifdef BRACKET_ELISION
    struct pt b[] = { 1, 2, 3, 4 };
#else
    struct pt b[] = { { 1, 2 }, { 3, 4 } };
#endif
    CHECK(COUNT(b) == 2);
    CHECK(b[1].x == 3 && b[1].y == 4);

    struct pt c[] = { { 1 }, { 2, 3 } };
    CHECK(COUNT(c) == 2);
    CHECK(c[0].y == 0);

    struct W { int v[2]; } w[] = { { { 1, 2 } }, { { 3, 4 } } };
    CHECK(COUNT(w) == 2);
    CHECK(w[1].v[0] == 3);

#ifdef BRACKET_ELISION
    struct W w2[] = { 1, 2, 3, 4, 5 };
#else
    struct W w2[] = { { { 1, 2 } }, { { 3, 4 } }, { { 5, 0 } } };
#endif
    CHECK(COUNT(w2) == 3);
    CHECK(w2[2].v[0] == 5 && w2[2].v[1] == 0);

    const char *names[] = { "a", "bb", "ccc" };
    CHECK(COUNT(names) == 3);
    CHECK(slen(names[2]) == 3);

    const char *words[] = { "a", "bb", "ccc", 0 };
    int n = 0, tot = 0;
    CHECK(COUNT(words) == 4);
    while (words[n]) {
        tot += slen(words[n]);
        n++;
    }
    CHECK(n == 3);
    CHECK(tot == 6);

    int (*fp[])(int) = { twice, neg, twice };
    CHECK(COUNT(fp) == 3);
    CHECK(fp[1](4) == -4);
    CHECK(fp[2](4) == 8);

    struct pt *pp[] = { &a[0], &a[2] };
    CHECK(COUNT(pp) == 2);
    CHECK(pp[1]->y == 6);

#ifdef BRACKET_ELISION
    struct pt e[] = { [1].y = 5, [0].x = 2 };
#else
    struct pt e[] = { [1] = {.y = 5}, [0] = {.x = 2} };
#endif
    CHECK(COUNT(e) == 2);
    CHECK(e[1].y == 5 && e[0].x == 2);
    CHECK(e[0].y == 0 && e[1].x == 0);

    const char *tbl[][2] = { { "a", "b" }, { "c", "d" } };
    CHECK(COUNT(tbl) == 2);
    CHECK(COUNT(tbl[0]) == 2);
    CHECK(tbl[1][1][0] == 'd');
    return 0;
}

/* 10: designators on multi-dimensional arrays */
static int t10_designators_2d(void)
{
    enum { T = 10 };
#ifdef BRACKET_ELISION
    int a[][3] = { [1][2] = 7 };
#else
    int a[][3] = { [1] = {[2] = 7} };
#endif
    CHECK(COUNT(a) == 2);
    CHECK(a[1][2] == 7);
    CHECK(a[0][0] == 0 && a[1][0] == 0);

    int b[][2] = { [2] = { 1, 2 }, [0] = { 3, 4 } };
    CHECK(COUNT(b) == 3);
    CHECK(b[0][0] == 3 && b[0][1] == 4);
    CHECK(b[1][0] == 0 && b[1][1] == 0);
    CHECK(b[2][0] == 1 && b[2][1] == 2);

#ifdef BRACKET_ELISION
    int c[][2] = { [1] = { 1 }, 5, 6 };
#else
    int c[][2] = { [1] = { 1, 0 }, { 5, 6 } };
#endif
    CHECK(COUNT(c) == 3);
    CHECK(c[1][0] == 1 && c[1][1] == 0);
    CHECK(c[2][0] == 5 && c[2][1] == 6);

#ifdef BRACKET_ELISION
    int d[][2] = { [1][1] = 4, 5 };
#else
    int d[][2] = { [1] = {[1] = 4}, { 5, 0 } };
#endif
    CHECK(COUNT(d) == 3);
    CHECK(d[1][1] == 4);
    CHECK(d[2][0] == 5 && d[2][1] == 0);
    return 0;
}

/* 11: typedefs of incomplete array types complete per declaration */
static int t11_typedefs(void)
{
    enum { T = 11 };
    Arr a = { 1, 2 };
    Arr b = { 1, 2, 3, 4 };
    CHECK(SZ(a) == 2 * SZ(int));
    CHECK(SZ(b) == 4 * SZ(int));
    CHECK(COUNT(a) == 2 && COUNT(b) == 4);

    M3 m1 = { { 1, 2, 3 } };
    M3 m2 = { { 1, 2, 3 }, { 4, 5, 6 } };
    CHECK(SZ(m1) == 3 * SZ(int));
    CHECK(SZ(m2) == 6 * SZ(int));
    CHECK(COUNT(m1) == 1 && COUNT(m2) == 2);
    CHECK(m2[1][2] == 6);

    Str s = "hi";
    Str t = "hello";
    CHECK(SZ(s) == 3);
    CHECK(SZ(t) == 6);

    Row3 r = { 1, 2, 3 };
    CHECK(SZ(r) == 3 * SZ(int));
    return 0;
}

/* 12: compound literals with unspecified size */
static int t12_compound_literals(void)
{
    enum { T = 12 };
    CHECK(SZ((int[]){ 1, 2, 3 }) == 3 * SZ(int));
    CHECK(SZ((int[]){ [3] = 1 }) == 4 * SZ(int));
    CHECK(SZ((int[][2]){ { 1, 2 }, { 3, 4 }, { 5, 6 } }) == 6 * SZ(int));
    CHECK(SZ((char[]){ "abc" }) == 4);
    CHECK(COUNT((int[]){ 1, 2, 3, 4, 5 }) == 5);
    CHECK(sum((int[]){ 1, 2, 3, 4 }, 4) == 10);
    CHECK(sum2((int[][3]){ { 1, 2, 3 }, { 4, 5, 6 } }, 2) == 21);
    CHECK((int[]){ 7, 8, 9 }[1] == 8);

    int *p = (int[]){ 7, 8, 9 };
    CHECK(p[1] == 8);
    p[1] = 80;
    CHECK(p[1] == 80);
    CHECK(sum(p, 3) == 96);
    return 0;
}

/* 13: sizeof idioms, constant dimensions, pointer arithmetic */
static int t13_sizeof_idioms(void)
{
    enum { T = 13 };
    int a[] = { 1, 2, 3, 4 };
    int b[COUNT(a)];                      /* constant dimension */
    CHECK(SZ(b) == 4 * SZ(int));
    CHECK(COUNT(b) == 4);

    CHECK(&a[COUNT(a)] - a == 4);
    CHECK((char *)(&a + 1) - (char *)a == SZ(a));
    CHECK(a == &a[0]);
    CHECK(*a == 1 && *(a + 3) == 4);
    CHECK(&a[3] - &a[1] == 2);

    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int rows[COUNT(m)];
    int cols[COUNT(m[0])];
    CHECK(SZ(rows) == 3 * SZ(int));
    CHECK(SZ(cols) == 3 * SZ(int));
    CHECK((char *)(&m + 1) - (char *)m == SZ(m));
    CHECK((char *)(m + 1) - (char *)m == 3 * SZ(int));

    int src[] = { 1, 2, 3, 4 };
    int dst[COUNT(src)];
    int i;
    for (i = 0; i < (int)COUNT(src); i++)
        dst[i] = src[i];
    for (i = 0; i < (int)COUNT(src); i++)
        CHECK(dst[i] == src[i]);

    char s1[] = "abc";
    char s2[sizeof(s1)];
    for (i = 0; i < SZ(s1); i++)
        s2[i] = s1[i];
    CHECK(slen(s2) == 3);
    return 0;
}

/* 14: static and const unsized arrays */
static int t14_static_const(void)
{
    enum { T = 14 };
    static const int tbl[] = { 1, 2, 3 };
    CHECK(COUNT(tbl) == 3);
    CHECK(tbl[2] == 3);

    static char sc[] = "abc";
    sc[0] = 'z';
    CHECK(SZ(sc) == 4);
    CHECK(sc[0] == 'z');

    const int ci[] = { 1, 2, 3 };
    const char cs[] = "ab";
    CHECK(SZ(ci) == 3 * SZ(int));
    CHECK(SZ(cs) == 3);

    CHECK(bump() == 13);
    CHECK(bump() == 23);
    CHECK(bump() == 33);

    CHECK(tbl_count() == 4);
    CHECK(tbl_ptr()[2] == 6);
    tbl_ptr()[2] = 60;
    CHECK(tbl_ptr()[2] == 60);
    CHECK(tbl_count() == 4);
    return 0;
}

/* 15: one-dimensional array parameters */
static int t15_params_1d(void)
{
    enum { T = 15 };
    int a[] = { 1, 2, 3, 4, 5 };
    CHECK(sum(a, (int)COUNT(a)) == 15);
    CHECK(sum(a + 1, 3) == 9);
    CHECK(param_sz1(a) == SZ(int *));
    CHECK(param_sz10(a) == SZ(int *));
    CHECK(param_sz1(a) != SZ(a));

    int one[] = { 9 };
    CHECK(sum(one, 1) == 9);

    fill(a, 3, 7);
    CHECK(a[0] == 7 && a[1] == 7 && a[2] == 7);
    CHECK(a[3] == 4 && a[4] == 5);
    CHECK(sum(&a[2], 3) == 16);

    reverse(a, 5);
    CHECK(a[0] == 5 && a[1] == 4 && a[2] == 7 && a[3] == 7 && a[4] == 7);

    char s[] = "hello";
    CHECK(slen(s) == 5);
    CHECK(slen(s + 2) == 3);
    CHECK(slen("abcd") == 4);
    return 0;
}

/* 16: two-dimensional array parameters */
static int t16_params_2d(void)
{
    enum { T = 16 };
    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    CHECK(sum2(m, (int)COUNT(m)) == 21);
    CHECK(sum2p(m, 2) == 21);
    CHECK(sum2f(m) == 7);
    CHECK(sum2(m, 0) == 0);
    CHECK(param_sz2(m) == SZ(int *));
    CHECK(param_sz_row(m) == 3 * SZ(int));
    CHECK(param_sz_der(m) == 3 * SZ(int));

    int big[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    CHECK(sum2(big + 1, 2) == 39);
    CHECK(sum2(&big[2], 1) == 24);
    CHECK(sum2f(big) == 7);

    fill2(m, 2, 9);
    CHECK(sum2(m, 2) == 54);
    CHECK(m[1][2] == 9);
    return 0;
}

/* 17: 3D parameters, char 2D parameters, pointer to incomplete array */
static int t17_params_misc(void)
{
    enum { T = 17 };
    int t[][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
    CHECK(sum3(t, 2) == 36);
    CHECK(sum3(t + 1, 1) == 26);

    char n[][4] = { "abc", "de", "f" };
    CHECK(names_total(n, 3) == 6);

    int a[] = { 1, 2, 3 };
    CHECK(via_incomplete(&a) == 2);

    int (*pi)[] = &a;
    CHECK((*pi)[2] == 3);
    (*pi)[0] = 9;
    CHECK(a[0] == 9);
    return 0;
}

/* 18: C99 qualifiers inside array parameter brackets */
static int t18_param_qualifiers(void)
{
    enum { T = 18 };
    int a[] = { 1, 2, 3 };
    CHECK(first3(a) == 6);
    CHECK(first3((int[]){ 4, 5, 6 }) == 15);
    CHECK(const_param(a, 3) == 6);
    CHECK(a[0] == 3);
    return 0;
}

/* 19: functions returning pointers to arrays / unsized statics */
static int t19_returns(void)
{
    enum { T = 19 };
    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

    CHECK((*row_ptr(m, 1))[2] == 6);
    CHECK(row_ptr(m, 2)[0][0] == 7);
    CHECK(row_ptr(m, 2) == &m[2]);
    CHECK(row_ptr(m, 2) == m + 2);
    CHECK((*row_ptr2(m, 0))[1] == 2);
    CHECK(SZ(*row_ptr(m, 0)) == 3 * SZ(int));
    CHECK(sum((int *)row_ptr(m, 1), 3) == 15);
    return 0;
}

/* 20: extern arrays of incomplete type */
static int t20_extern(void)
{
    enum { T = 20 };
    CHECK(use_ext_before() == 130);
    CHECK(block_extern_before() == 904);

    CHECK(SZ(g_ext1) == 3 * SZ(int));
    CHECK(COUNT(g_ext1) == 3);
    CHECK(g_ext1[2] == 30);

    CHECK(COUNT(g_ext2) == 2);
    CHECK(SZ(g_ext2[0]) == 3 * SZ(int));
    CHECK(g_ext2[1][0] == 4);

    CHECK(SZ(g_ext_str) == 6);
    CHECK(g_ext_str[4] == 'o');

    CHECK(SZ(g_ext3) == 4 * SZ(int));
    CHECK(SZ(g_ext4) == 6 * SZ(int));
    CHECK(COUNT(g_ext4) == 3);

    CHECK(COUNT(g_ext_pts) == 3);
    CHECK(g_ext_pts[2].x == 5);

    CHECK(COUNT(g_late) == 3);
    CHECK(COUNT(g_late2) == 2);

    CHECK(g_tent[0] == 0);
    g_tent[0] = 5;
    CHECK(g_tent[0] == 5);

    {
        extern int g_ext1[];              /* block-scope redeclaration */
        // CHECK(COUNT(g_ext1) == 3);
        CHECK(g_ext1[0] == 10);
    }
    {
        extern int g_ext2[][3];
        CHECK(sum2(g_ext2, 2) == 21);
        // CHECK(COUNT(g_ext2) == 2);
    }
    return 0;
}

/* 21: extern arrays accessed through pointers / functions */
static int t21_extern_access(void)
{
    enum { T = 21 };
    int *p = g_ext1;
    CHECK(sum(g_ext1, 3) == 60);
    p[1] = 21;
    CHECK(g_ext1[1] == 21);
    p[1] = 20;
    CHECK(sum(g_ext1, (int)COUNT(g_ext1)) == 60);

    int (*pm)[3] = g_ext2;
    pm[1][1] = 50;
    CHECK(g_ext2[1][1] == 50);
    pm[1][1] = 5;
    CHECK(sum2(g_ext2, 2) == 21);

    char *s = g_ext_str;
    s[0] = 'J';
    CHECK(g_ext_str[0] == 'J');
    CHECK(slen(g_ext_str) == 5);
    s[0] = 'h';

    struct pt *pp = g_ext_pts;
    CHECK(pp[1].y == 4);
    CHECK(sum((int *)g_ext4, 6) == 21);
    return 0;
}

/* 22: file-scope unsized arrays and initializers */
static int t22_globals(void)
{
    enum { T = 22 };
    int i, s = 0;
    static int *sp[] = { &g_tbl[0], &g_tbl[2] };

    CHECK(COUNT(g_tbl) == 4);
    CHECK(SZ(g_copy) == SZ(g_tbl));
    CHECK(COUNT(g_copy) == 4);
    for (i = 0; i < (int)COUNT(g_copy); i++) {
        g_copy[i] = g_tbl[i];
        s += g_copy[i];
    }
    CHECK(s == 50);

    CHECK(SZ(g_msg) == 7);
    CHECK(slen(g_msg) == 6);

    CHECK(COUNT(g_names) == 4);
    CHECK(SZ(g_names[0]) == 6);
    CHECK(g_names[2][4] == 'e');
    CHECK(slen(g_names[3]) == 4);

    CHECK(COUNT(g_des) == 6);
    CHECK(g_des[4] == 1 && g_des[5] == 2 && g_des[0] == 0);

    CHECK(COUNT(g_ptrs) == 3);
    CHECK(g_ptrs[0][1] == 2);
    CHECK(g_ptrs[1][2] == 5);
    CHECK(*g_ptrs[2] == 10);

    CHECK(g_tb.n == 4);
    CHECK(g_tb.d[3] == 20);

    CHECK(COUNT(g_m) == 3);
    CHECK(g_m[2][1] == 6);

    CHECK(COUNT(sp) == 2);
    CHECK(sp[1][0] == 15);
    return 0;
}

/* 23: pointers to arrays derived from unsized arrays */
static int t23_pointer_to_array(void)
{
    enum { T = 23 };
    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int (*pa)[3] = m;
    CHECK(pa[1][2] == 6);
    CHECK((*(pa + 2))[0] == 7);
    CHECK(pa + 3 == m + COUNT(m));

    int (*p3)[3] = &m[1];
    CHECK(p3[0][0] == 4);
    CHECK(p3[1][0] == 7);

    CHECK(&m[2] - &m[0] == 2);
    CHECK(**m == 1);
    CHECK(*(*(m + 1) + 1) == 5);
    CHECK(*m[2] == 7);

    int a[] = { 1, 2, 3 };
    int (*pi)[3] = &a;
    CHECK((*pi)[1] == 2);
    CHECK(SZ(*pi) == 3 * SZ(int));

    int (*pu)[] = &a;
    CHECK((*pu)[2] == 3);
    return 0;
}

/* 24: sort / reverse on unsized arrays */
static int t24_sort(void)
{
    enum { T = 24 };
    int a[] = { 5, 2, 9, 1, 7, 3 };
    sort(a, (int)COUNT(a));
    CHECK(a[0] == 1 && a[1] == 2 && a[2] == 3);
    CHECK(a[3] == 5 && a[4] == 7 && a[5] == 9);
    CHECK(sum(a, (int)COUNT(a)) == 27);

    reverse(a, (int)COUNT(a));
    CHECK(a[0] == 9 && a[1] == 7 && a[2] == 5);
    CHECK(a[3] == 3 && a[4] == 2 && a[5] == 1);
    return 0;
}

/* 25: matrix multiplication / transposition with unsized matrices */
static int t25_matrix(void)
{
    enum { T = 25 };
    int a[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    int b[][3] = { { 1, 0, 2 }, { 0, 1, 3 } };
    int c[3][3];

    CHECK(COUNT(a) == 3);
    CHECK(COUNT(a[0]) == 2);
    CHECK(COUNT(b) == COUNT(a[0]));
    CHECK(COUNT(b[0]) == 3);

    matmul(a, b, c, (int)COUNT(a));
    CHECK(c[0][0] == 1 && c[0][1] == 2 && c[0][2] == 8);
    CHECK(c[1][0] == 3 && c[1][1] == 4 && c[1][2] == 18);
    CHECK(c[2][0] == 5 && c[2][1] == 6 && c[2][2] == 28);

    int bt[3][2];
    int i, j;
    for (i = 0; i < (int)COUNT(b); i++)
        for (j = 0; j < (int)COUNT(b[0]); j++)
            bt[j][i] = b[i][j];
    CHECK(bt[2][0] == 2 && bt[2][1] == 3);
    CHECK(bt[1][1] == 1 && bt[0][1] == 0);
    return 0;
}

/* 26: scoping and shadowing of unsized arrays */
static int t26_scopes(void)
{
    enum { T = 26 };
    int a[] = { 1 };
    {
        int a[] = { 1, 2, 3 };
        CHECK(COUNT(a) == 3);
        {
            int a[] = { 1, 2, 3, 4, 5 };
            CHECK(COUNT(a) == 5);
        }
        CHECK(COUNT(a) == 3);
    }
    CHECK(COUNT(a) == 1);

    int b[] = { a[0], a[0] + 1, 3, 4 };
    CHECK(COUNT(b) == 4);
    CHECK(b[1] == 2);
    return 0;
}

/* 27: decay in expressions */
static int t27_decay(void)
{
    enum { T = 27 };
    int a[] = { 1, 2, 3 };
    int b[] = { 1, 2 };
    int c = 1;
    int *p = a;

    CHECK(SZ(c ? a : b) == SZ(int *));
    CHECK((c ? a : b)[1] == 2);
    CHECK(a != b);
    CHECK(p == a);
    CHECK(SZ(a + 0) == SZ(int *));
    CHECK(SZ(*a) == SZ(int));
    CHECK(SZ(&a) == SZ(int *));
    CHECK(SZ(a) == 3 * SZ(int));
    CHECK(*(a + 1) == 2);
    CHECK(1 [a] == 2);
    return 0;
}

/* 28: dimensions given by enums / macros combined with unsized rows */
static int t28_enum_dims(void)
{
    enum { T = 28 };
    int m[][COLS] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
    CHECK(COUNT(m) == 2);
    CHECK(COUNT(m[0]) == COLS);
    CHECK(SZ(m) == 8 * SZ(int));

    int lut[] = { [EA] = 1, [EB] = 2, [EC] = 3 };
    CHECK(COUNT(lut) == 3);
    CHECK(lut[EC] == 3);

#ifdef BRACKET_ELISION
    int n[][COLS] = { 1, 2, 3, 4, 5 };
#else
    int n[][COLS] = { { 1, 2, 3, 4 }, { 5, 0, 0, 0 } };
#endif
    CHECK(COUNT(n) == 2);
    CHECK(n[1][0] == 5 && n[1][1] == 0);
    return 0;
}

/* 29: compatible declarations with array-adjusted parameters */
static int t29_compat(void)
{
    enum { T = 29 };
    int m[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    int a[] = { 7, 8, 9 };

    CHECK(cmp1(m) == 4);
    CHECK(cmp2(a) == 8);
    CHECK(cmp3(m) == 6);
    CHECK(cmp4(a) == 9);
    return 0;
}

/* 30: table of structs sized by initializer, string-key lookup */
static int t30_struct_table(void)
{
    enum { T = 30 };
    static const struct E e[] = { { "a", 1 }, { "bb", 2 }, { "ccc", 3 } };

    CHECK(COUNT(e) == 3);
    CHECK(SZ(e[0]) == SZ(struct E));
    CHECK(lookup(e, (int)COUNT(e), "bb") == 2);
    CHECK(lookup(e, (int)COUNT(e), "ccc") == 3);
    CHECK(lookup(e, (int)COUNT(e), "zz") == -1);
    return 0;
}

/* ------------------------------------------------------------------ */

#define RUN(f) do { int r_ = f(); if (r_) return r_; } while (0)

int main(void)
{
    RUN(t01_basic);
    RUN(t02_nonconstant_init);
    RUN(t03_designators);
    RUN(t04_strings);
    RUN(t05_2d_braced);
    RUN(t06_2d_elision);
    RUN(t07_3d);
    RUN(t08_char_2d);
    RUN(t09_aggregates);
    RUN(t10_designators_2d);
    RUN(t11_typedefs);
    RUN(t12_compound_literals);
    RUN(t13_sizeof_idioms);
    RUN(t14_static_const);
    RUN(t15_params_1d);
    RUN(t16_params_2d);
    RUN(t17_params_misc);
    RUN(t18_param_qualifiers);
    RUN(t19_returns);
    RUN(t20_extern);
    RUN(t21_extern_access);
    RUN(t22_globals);
    RUN(t23_pointer_to_array);
    RUN(t24_sort);
    RUN(t25_matrix);
    RUN(t26_scopes);
    RUN(t27_decay);
    RUN(t28_enum_dims);
    RUN(t29_compat);
    RUN(t30_struct_table);
    return 0;
}