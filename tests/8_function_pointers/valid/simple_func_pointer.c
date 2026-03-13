// Exit code: 0
int add(int a, int b) { 
    return a + b; 
}

int main(void) {
    int (*math_op)(int, int) = add;
    int val = math_op(2, 5);
    if(val != 7) return 1;
    return 0;
}
