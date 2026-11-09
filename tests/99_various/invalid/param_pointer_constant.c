// test_param_pointer_const.c
void process(int a[const 5]) {
    int other_arr[5] = {0};
    a = other_arr; // ERROR: assignment of read-only parameter 'a'
}

int main(void) {
    int base[5] = {1};
    process(base);
    return 0;
}