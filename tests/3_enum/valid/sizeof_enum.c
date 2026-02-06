// Exit code: 0
/* Test: sizeof enum vs int. */
enum E { A };
int main() {
    /* C standard says enum is compatible with some integer type. 
       Usually int, but compiler dependent. Checking basic sanity. */
    if (sizeof(enum E) == 0) return 1;
    return 0;
}