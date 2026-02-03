// Exit code: 0
/* Test array of structs containing arrays */
struct Complex {
    float val[2]; 
};

int main() {
    struct Complex arr[2] = {
        {{1.0f, 2.0f}},
        {{3.0f, 4.0f}}
    };
    
    if (arr[1].val[0] != 3.0f) return 1;
    return 0;
}