// Exit code: 0
/* Test: Self-referential struct with enum data. */
enum Data { D1, D2 };
struct Node {
    enum Data d;
    struct Node *next;
};
int main() {
    struct Node n1;
    struct Node n2;
    n1.d = D1; n1.next = &n2;
    n2.d = D2; n2.next = 0;
    
    if (n1.next->d != D2) return 1;
    return 0;
}