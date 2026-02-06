// Exit code: 0
/* Test: Complex interaction: Struct containing array of enums. */
enum Status { OK, FAIL };
struct Res {
    enum Status logs[2];
};
int main() {
    struct Res r;
    r.logs[0] = OK;
    r.logs[1] = FAIL;
    if (r.logs[0] != 0) return 1;
    if (r.logs[1] != 1) return 2;
    return 0;
}