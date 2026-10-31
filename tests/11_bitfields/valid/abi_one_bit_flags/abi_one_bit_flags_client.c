/* abi_one_bit_flags_client.c -- compile with the compiler under test */
#include "abi_one_bit_flags_common.h"

static struct S loc_A, loc_B;
static struct S arr[5];

/* Called by the server (gcc).  Returns B for input A/77, A otherwise. */
static struct S cli_callback(struct S s, int k)
{
    struct S r = zero_s;
    if (k == 77 && check_A(&s) == 0) { set_B(&r); return r; }
    set_A(&r);
    return r;
}

static void cli_callback_ptr(struct S *p)
{
    if (check_A(p) == 0) set_B(p);
}

int main(void)
{
    struct S s, t;
    unsigned long i;
    int k, rc;

    /* ---- layout agreement ------------------------------------------- */
    if (srv_sizeof_S() != sizeof(struct S)) return 1;
    if (srv_alignof_S() != alignof_S()) return 2;
    set_A(&loc_A);
    for (i = 0; i < sizeof(struct S); i++)
        if (((unsigned char *)&loc_A)[i] != ((const unsigned char *)&srv_global_A)[i])
            return 3;                                  /* bit positions differ */

    /* ---- client reads server data ------------------------------------ */
    if ((rc = check_A(&srv_global_A)) != 0) return 32 + rc;
    s = srv_make_A();
    if ((rc = check_A(&s)) != 0) return 48 + rc;
    t = srv_make_B();
    if ((rc = check_B(&t)) != 0) return 64 + rc;

    /* ---- client passes by value to server ---------------------------- */
    s = zero_s; set_A(&s);
    if (srv_check_A(s) != 0) return 80;
    t = zero_s; set_B(&t);
    if (srv_check_B(t) != 0) return 96;

    /* ---- by pointer -------------------------------------------------- */
    if (srv_check_A_ptr(&loc_A) != 0) return 112;
    srv_set_B_ptr(&loc_B);
    if ((rc = check_B(&loc_B)) != 0) return 128 + rc;

    /* ---- arrays ------------------------------------------------------ */
    srv_fill_array(arr, 5);
    for (k = 0; k < 5; k++)
        if ((k % 2 == 0) ? check_A(&arr[k]) : check_B(&arr[k])) return 144 + k;
    for (k = 0; k < 5; k++) {
        arr[k] = zero_s;
        if (k % 2 == 0) set_A(&arr[k]); else set_B(&arr[k]);
    }
    if (srv_check_array(arr, 5) != 0) return 150;

    /* ---- argument passing mixes ------------------------------------- */
    s = zero_s; set_A(&s);
    t = zero_s; set_B(&t);
    if (srv_mixed_args(11, s, 2.5, t, -33) != 0) return 160;
    if (srv_many_args(1, 2, 3, 4, s, t, 5, 6, s, 7) != 0) return 161;

    /* ---- callbacks into this (client) module ------------------------- */
    if (srv_call_client(cli_callback) != 0) return 176;
    if (srv_call_client_ptr(cli_callback_ptr) != 0) return 177;

    /* ---- shared global written here, checked by the server ----------- */
    set_A(&srv_global_in);
    if (srv_check_global_in() != 0) return 192;
    set_first_B(&srv_global_in);                       /* must not clobber neighbours */
    if (srv_check_global_first_B() != 0) return 193;

    return 0;
}
