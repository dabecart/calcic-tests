// Exit code: 0
int simpleRet(void) { 
    return 55; 
}

int main(void) {
    int (*fp)(void) = simpleRet;
    int val = fp();
    if(val != 55) return 117;
    return 0;
}
