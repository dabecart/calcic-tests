// Exit code: 0

/* Tests 'Usual Arithmetic Conversions' in comparisons.
   When comparing signed int and unsigned int, the signed int
   is converted to unsigned int. */
   
int neg = -1;
unsigned int pos = 1;

/* -1 (signed) becomes UINT_MAX (unsigned).
   UINT_MAX > 1 is TRUE. */
int res = (-1 > 1U); 

int main() {
    if (res != 1) return 1; /* If 0, compiler failed promotion logic */
    if (neg < pos) return 2; /* Runtime check should match static */
    return 0;
}