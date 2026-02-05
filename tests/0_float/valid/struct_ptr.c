// Exit code: 0
/* Test pointer to struct with floats */
struct Data { float v; };

int main() {
    struct Data d = { 10.0f };
    struct Data *p = &d;
    
    if (p->v != 10.0f) return 1;
    
    p->v = 20.0f;
    if (d.v != 20.0f) return 2;
    return 0;
}