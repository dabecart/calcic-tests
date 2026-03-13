// Exit code: 0
int mul(int a, int b) { 
    return a * b; 
}

int div(int a, int b) { 
    return a / b; 
}

int main(void) {
    int (*ops[2])(int, int) = {mul, div};
    int val1 = ops[0](4, 3);
    if(val1 != 12) return 102;
    int val2 = ops[1](10, 2);
    if(val2 != 5) return 103;
    return 0;
}
