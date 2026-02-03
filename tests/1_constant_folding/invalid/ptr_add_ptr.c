/* Illegal Binary Operation: Pointer + Pointer.
   You cannot add two addresses together.
*/
int arr[10];
int *p = arr + arr; /* Error */
int main() { return 0; }