// Exit code: 0
// Basic interactions of typedef with tagless structs, pointers, and arithmetic.

/* Tagless struct via typedef */
typedef struct {
    int id;
    float weight;
} Item;

/* Tagless union via typedef */
typedef union {
    int i;
    float f;
} Number;

int main(void) {
    /* 1. Initialization and Access */
    Item it = { 10, 5.5f };
    
    if (it.id != 10) return 1;
    if (it.weight != 5.5f) return 2;

    /* 2. Pointer Interaction */
    Item *ptr = &it;
    ptr->id = 20;
    
    if (it.id != 20) return 3;

    /* 3. Union Interaction */
    Number n;
    n.i = 42;
    /* Basic sanity check that union shares memory */
    if (n.i != 42) return 4;
    
    n.f = 123.456f;
    /* Re-reading i should now be 'garbage' (representation of float), 
       but checking f validity is the standard test */
    if (n.f != 123.456f) return 5;

    /* 4. Pointer Arithmetic on Tagless Types */
    Item arr[2] = { {1, 1.0f}, {2, 2.0f} };
    Item *pArr = arr;
    pArr++; 
    
    if (pArr->id != 2) return 6;

    return 0;
}
