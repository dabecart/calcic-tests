// Exit code: 0

/* Tests binary operators on pointers in static initializers.
   The compiler must verify that pointers point to the same object
   before folding the result to an integer constant.
*/

int arr[10];
int *base = arr;

/* 1. Pointer Subtraction (Ptr - Ptr) -> Integer Constant */
long diff_1 = &arr[5] - &arr[2];        /* 3 */
long diff_2 = &arr[0] - &arr[0];        /* 0 */
long diff_3 = (arr + 8) - (arr + 1);    /* 7 */

/* 2. Relational Operators (Ptr <, >, <=, >= Ptr) -> Integer Constant (0 or 1) */
int rel_1 = &arr[0] < &arr[1];          /* 1 */
int rel_2 = &arr[5] > &arr[2];          /* 1 */
int rel_3 = &arr[2] <= &arr[2];         /* 1 */
int rel_4 = &arr[8] >= &arr[9];         /* 0 */
int rel_5 = (arr + 2) < (arr + 5);      /* 1 */

/* 3. Equality Operators (Ptr ==, != Ptr) -> Integer Constant (0 or 1) */
int eq_1 = &arr[3] == (arr + 3);        /* 1 */
int eq_2 = &arr[0] != &arr[1];          /* 1 */
int eq_3 = (arr + 5) == (arr + 4);      /* 0 */

int main() {
    if (diff_1 != 3) return 1;
    if (diff_2 != 0) return 2;
    if (diff_3 != 7) return 3;
    
    if (rel_1 != 1) return 4;
    if (rel_2 != 1) return 5;
    if (rel_3 != 1) return 6;
    if (rel_4 != 0) return 7;
    if (rel_5 != 1) return 8;

    if (eq_1 != 1) return 9;
    if (eq_2 != 1) return 10;
    if (eq_3 != 0) return 11;
    
    return 0;
}