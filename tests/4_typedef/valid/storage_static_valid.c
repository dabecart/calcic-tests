// Exit code: 0
typedef int T;
static T global_static = 10;

int main(void) {
    static T local_static = 20;
    if (global_static != 10) return 1;
    if (local_static != 20) return 2;
    return 0;
}