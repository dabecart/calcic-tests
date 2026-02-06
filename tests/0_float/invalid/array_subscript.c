/* Error: Array subscript must be integer, not float */
int main() {
    int arr[10];
    float idx = 2.0f;
    int val = arr[idx];
    return 0;
}