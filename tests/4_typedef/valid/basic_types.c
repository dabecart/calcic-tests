// Exit code: 0
typedef int MyInt;
typedef short MyShort;
typedef char MyChar;

int main(void) {
    MyInt i = 10;
    MyShort s = 20;
    MyChar c = 'A';
    
    if (i != 10) return 1;
    if (s != 20) return 2;
    if (c != 'A') return 3;
    if (sizeof(MyInt) != sizeof(int)) return 4;
    
    return 0;
}