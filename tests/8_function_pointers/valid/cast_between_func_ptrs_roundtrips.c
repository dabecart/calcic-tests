// Exit code: 0
int do_work(int a) { 
    return a * 2; 
}

int main(void) {
    void (*generic_fp)(void) = (void (*)(void)) do_work;
    int (*restored_fp)(int) = (int (*)(int)) generic_fp;
    int val = restored_fp(4);
    if(val != 8) return 112;
    return 0;
}
