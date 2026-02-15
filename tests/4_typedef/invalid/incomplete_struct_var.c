// Error: variable has incomplete type
typedef struct Node Node;
int main(void) {
    Node n; // Struct Node never defined
    return 0;
}