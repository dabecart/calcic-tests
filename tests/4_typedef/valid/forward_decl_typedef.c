// Exit code: 0
struct Item;
typedef struct Item Item;
struct Container {
    Item *ptr;
};
struct Item { int id; };

int main(void) {
    Item i = {99};
    struct Container c;
    c.ptr = &i;
    if (c.ptr->id != 99) return 1;
    return 0;
}