// Exit code: 0
/* Test: Inner scope enum shadowing outer scope enum tag. */
enum E { A = 1 };
int main() {
    if (A != 1) return 1;
    {
        enum E { A = 2 }; // Shadowing definition
        if (A != 2) return 2;
    }
    if (A != 1) return 3; // Should return to outer
    return 0;
}