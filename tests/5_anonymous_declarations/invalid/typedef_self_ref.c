// A tagless struct cannot reference itself via pointer because it has no tag.
// Attempting to use the typedef name inside the struct is invalid 
// because the typedef is not complete until the semicolon.

typedef struct {
    int value;
    /* ERROR: 'Node' is not yet defined at this point. 
       Unlike 'struct Node *next;', we cannot use the typedef name here. */
    Node *next; 
} Node;

int main(void) {
    Node n;
    return 0;
}
