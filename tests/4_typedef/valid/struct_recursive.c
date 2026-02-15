// Exit code: 0
struct Node;
typedef struct Node Node;
struct Node {
    int val;
    Node *next;
};

int main(void) {
    Node n1;
    Node n2;
    n1.val = 1;
    n1.next = &n2;
    n2.val = 2;
    n2.next = 0;
    
    if (n1.next->val != 2) return 1;
    return 0;
}