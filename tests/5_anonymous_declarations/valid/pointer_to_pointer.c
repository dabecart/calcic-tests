// Exit code: 0
// Double indirection with tagless types.
typedef struct { float f; } Data;

int main(void) {
    Data d = { 3.14f };
    Data *p = &d;
    Data **pp = &p;

    if ((**pp).f != 3.14f) return 1;

    /* Change value via double pointer */
    (**pp).f = 0.0f;
    if (d.f != 0.0f) return 2;

    return 0;
}
