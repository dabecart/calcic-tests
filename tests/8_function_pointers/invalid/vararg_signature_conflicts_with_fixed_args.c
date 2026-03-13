int v_func(int a, ...) { 
    return a; 
}

int main(void) {
    int (*fp)(int) = v_func;
    return 0;
}
