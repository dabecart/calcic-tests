int take_two(int a, int b) { 
    return a + b; 
}

int main(void) {
    int (*fp)(int) = take_two;
    return 0;
}
