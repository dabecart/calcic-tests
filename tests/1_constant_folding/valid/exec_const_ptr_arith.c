// Exit code: 0

/* Address constants and offsets */
int arr[10];
long diff = (arr + 5) - arr;  /* 5 */
int is_null = (void*)0 == 0;  /* 1 */

int main() {
    if (diff != 5) return 1;
    if (is_null != 1) return 2;
    return 0;
}