// Exit code: 0

/* Tests interaction between pointers and integer constants.
   (Address Constant + Integer Constant) -> Address Constant
*/

int arr[10];

/* Pointer + Integer */
int *p1 = arr + 2; 
int *p2 = 2 + arr; /* Commutative */

/* Pointer - Integer */
int *p3 = &arr[5] - 2; /* Should be &arr[3] */

/* Complex folding: &arr[2] - &arr[0] + 5 = 2 + 5 = 7 */
long complex_fold = (&arr[2] - arr) + 5; 

int main() {
    if (p1 != &arr[2]) return 1;
    if (p2 != &arr[2]) return 2;
    if (p3 != &arr[3]) return 3;
    if (complex_fold != 7) return 4;
    return 0;
}