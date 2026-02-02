// Exit code: 0

/* Tests casting pointers to different types and performing arithmetic.
   This forces the compiler to track byte offsets rather than just element indices.
*/

struct S {
    int a;
    int b;
} s_obj;

int arr[10];

/* Casting int* to char* to do byte-level arithmetic */
/* &arr[1] is 1 * sizeof(int) bytes ahead of &arr[0] */
long byte_diff = (char*)&arr[1] - (char*)&arr[0]; 

/* Casting struct* to char* to determine member offsets */
long member_offset = (char*)&s_obj.b - (char*)&s_obj.a;

/* Null Pointer Constants cast tests */
int *p_null_1 = (int*)0;
int *p_null_2 = (void*)0;

/* Logical NOT operator on pointers */
int is_null_1 = !p_null_1;        /* 1 */
int is_null_2 = !&arr[0];         /* 0 */

int main() {
    /* We expect sizeof(int) to be generally 4, but strictly > 1 */
    if (byte_diff != sizeof(int)) return 1;
    
    /* struct member 'b' follows 'a', offset should be sizeof(int) */
    if (member_offset != sizeof(int)) return 2;

    if (p_null_1 != 0) return 3;
    if (p_null_2 != 0) return 4;
    
    if (is_null_1 != 1) return 5;
    if (is_null_2 != 0) return 6;
    
    return 0;
}