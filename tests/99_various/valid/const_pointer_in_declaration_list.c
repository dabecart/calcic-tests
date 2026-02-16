// Exit code: 0
int main() {
    int val = 10, *p1 = &val, * const p2 = p1;
    
    if(*p2 != 10) return 1;
    return 0;
}