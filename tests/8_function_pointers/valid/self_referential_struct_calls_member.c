// Exit code: 0
struct Node;
struct Node {
    int value;
    int (*get_val)(struct Node*);
};
int node_val(struct Node* n) { return n->value; }
int main(void) {
    struct Node n = {88, node_val };
    int val = n.get_val(&n);
    if(val != 88) return 114;
    return 0;
}
