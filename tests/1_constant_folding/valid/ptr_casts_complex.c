// Exit code: 0

/* Tests casting pointers to different types and performing arithmetic.
   This forces the compiler to track byte offsets rather than just element indices.
*/

struct S {
    int a;
    int b;
};
struct S s_obj;

int arr[10];

/* &arr[1] is 1 * sizeof(int) bytes ahead of &arr[0] */
long byte_diff_1 = (char*)&arr[1] - (char*)&arr[0];
/* if arr where a short[], the first term would fall in [16] and the second in [4] */
long short_diff = (short*)&arr[8] - (short*)&arr[2]; 

char carr[13] = "hello reader";
long byte_diff_2 = &carr[5] - &carr[0];
/* if carr where an int[], the first term would fall in [2] and the second in [0].
You may be tempted to think this value would be 2 then, but that's not how it works.
You need to think in terms of byte offsets, first term is carr+8, second carr+1, byte
offset is 7, which is actually rounded down to one int, not two!*/
long int_diff = (int*)&carr[8] - (int*)&carr[1];

/* Casting struct* to char* to determine member offsets */
long member_offset = (char*)&s_obj.b - (char*)&s_obj.a;

/* Null Pointer Constants cast tests */
int *p_null_1 = (int*)0;
int *p_null_2 = (void*)0;

/* Logical NOT operator on pointers */
int is_null = !&arr[0];

int main() {
    if (byte_diff_1 != sizeof(int)) return 1;
    if (short_diff != 6*sizeof(int)/sizeof(short)) return 2;
    if (byte_diff_2 != 5*sizeof(char)) return 3;
    if (int_diff != 7*sizeof(char)/sizeof(int)) return 4;
    
    /* struct member 'b' follows 'a', offset should be sizeof(int) */
    if (member_offset != sizeof(int)) return 5;

    if (p_null_1 != 0) return 6;
    if (p_null_2 != 0) return 7;
    
    if (is_null != 0) return 8;
    
    return 0;
}