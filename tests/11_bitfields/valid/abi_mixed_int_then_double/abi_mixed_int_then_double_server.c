/* abi_mixed_int_then_double_server.c -- compile with gcc */
#include "abi_mixed_int_then_double_common.h"

struct S srv_global_A = {
    .a = -9,
    .b = 2047,
    .d = 3.25
};
struct S srv_global_in;

unsigned long srv_sizeof_S(void) { return sizeof(struct S); }
unsigned long srv_alignof_S(void) { return alignof_S(); }

struct S srv_make_A(void) { struct S s = zero_s; set_A(&s); return s; }
struct S srv_make_B(void) { struct S s = zero_s; set_B(&s); return s; }

int srv_check_A(struct S s) { return check_A(&s); }
int srv_check_B(struct S s) { return check_B(&s); }
int srv_check_A_ptr(const struct S *p) { return check_A(p); }
void srv_set_B_ptr(struct S *p) { set_B(p); }

int srv_check_array(const struct S *arr, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        int rc = (i % 2 == 0) ? check_A(&arr[i]) : check_B(&arr[i]);
        if (rc) return i + 1;
    }
    return 0;
}

void srv_fill_array(struct S *arr, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = zero_s;
        if (i % 2 == 0) set_A(&arr[i]); else set_B(&arr[i]);
    }
}

int srv_mixed_args(int a, struct S s, double d, struct S t, int b)
{
    if (a != 11) return 1;
    if (check_A(&s)) return 2;
    if (d != 2.5) return 3;
    if (check_B(&t)) return 4;
    if (b != -33) return 5;
    return 0;
}

int srv_many_args(int i1, int i2, int i3, int i4, struct S a, struct S b,
                  int i5, int i6, struct S c, int i7)
{
    if (i1 != 1 || i2 != 2 || i3 != 3 || i4 != 4) return 1;
    if (check_A(&a)) return 2;
    if (check_B(&b)) return 3;
    if (i5 != 5 || i6 != 6) return 4;
    if (check_A(&c)) return 5;
    if (i7 != 7) return 6;
    return 0;
}

/* The callback is compiled by the client's compiler. */
int srv_call_client(struct S (*cb)(struct S, int))
{
    struct S in = zero_s, out;
    set_A(&in);
    out = cb(in, 77);
    if (check_B(&out)) return 1;
    in = zero_s; set_B(&in);
    out = cb(in, 78);                 /* client must flag wrong input by returning A */
    if (check_A(&out)) return 2;
    return 0;
}

int srv_call_client_ptr(void (*cb)(struct S *))
{
    struct S s = zero_s;
    set_A(&s);
    cb(&s);
    return check_B(&s);
}

int srv_check_global_in(void) { return check_A(&srv_global_in); }
int srv_check_global_first_B(void) { return check_first_B_rest_A(&srv_global_in); }
