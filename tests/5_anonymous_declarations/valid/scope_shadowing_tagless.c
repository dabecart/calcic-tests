// Exit code: 0

// Scoping rules, shadowing of tagless types, and const qualifiers.
/* File scope tagless typedef */
typedef struct { int x; } Coord;

int main(void) {
    Coord c1 = { 100 };
    
    if (c1.x != 100) return 1;

    {
        /* BLOCK SCOPE: Shadowing 'Coord' with a different tagless struct */
        typedef struct { int y; int z; } Coord;

        if (c1.x != 100) return 2;
        
        Coord c2 = { 50, 60 };
        if (c2.y != 50) return 3;
        if (c2.z != 60) return 4;
        
        /* Ensure we didn't overwrite the outer type size logic implicitly */
        if (sizeof(Coord) == sizeof(int)) return 5; // Should be 2 ints
    }

    /* Back to file scope type */
    if (sizeof(Coord) != sizeof(int)) return 6;

    /* Const interaction with tagless type */
    const struct { int a; } constant_anon = { 999 };
    
    if (constant_anon.a != 999) return 7;

    /* Tagless Enum */
    enum { VAL_A = 10, VAL_B = 20 } my_enum_var;
    my_enum_var = VAL_B;
    
    if (my_enum_var != 20) return 8;

    return 0;
}
