// Exit code: 0
// Tests shadowing of tagless types.
// File scope vs Block scope vs Inner Block scope.

typedef struct { int x; } Obj; /* File scope */

int main(void) {
    Obj outer = { 10 };
    if (outer.x != 10) return 1;

    {
        /* Shadow file scope type with new tagless type */
        typedef struct { int x; int y; } Obj; 
        Obj inner = { 20, 30 };
        
        if (sizeof(Obj) == sizeof(int)) return 2; /* Should be larger */
        if (inner.x != 20) return 3;
        if (inner.y != 30) return 4;

        {
            /* Shadow again with union */
            typedef union { int x; char c; } Obj;
            Obj u;
            u.x = 0xFF;
            if (u.x != 0xFF) return 5;
        }
    }

    /* Back to file scope */
    if (sizeof(Obj) != sizeof(int)) return 6;
    return 0;
}
