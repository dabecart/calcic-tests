// Exit code: 0
// Valid C: Redeclaring typedef name as variable in inner scope
typedef int T;
int main(void) {
    int T = 5; // Valid, shadows type T
    return (T == 5) ? 0 : 1;
}