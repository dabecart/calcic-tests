// Exit code: 0
enum status { ERR = 0, OK = 1 };
enum status check_val(int a) { return (a > 0) ? OK : ERR; }
int main(void) {
    enum status (*checker)(int) = check_val;
    int val = checker(5);
    if(val != OK) return 107;
    return 0;
}
