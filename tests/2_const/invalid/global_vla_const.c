/* Test: Using const int for global array size. */
const int SIZE = 10;

// ERROR: Variably modified 'arr' at file scope
int arr[SIZE]; 

void test() {}

int main() {
    return 0;
}