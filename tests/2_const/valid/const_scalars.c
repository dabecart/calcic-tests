// Exit code: 0

int main() {
    /* 1. Standard const initialization */
    const int a = 10;
    if (a != 10) return 1;

    /* 2. Const variable used in arithmetic (Lvalue to Rvalue conversion) */
    int b = a + 5;
    if (b != 15) return 2;

    /* 3. Redundant qualifiers (C99 allow 'const const') */
    const const int c = 20; 
    if (c != 20) return 3;

    /* 4. Const correctly interacts with other types */
    const long d = 30;
    int e = (int)d; /* Explicit cast of value */
    if (e != 30) return 4;

    /* 5. Pointer to const scalar (reading is fine) */
    const int *ptr = &a;
    int val = *ptr;
    if (val != 10) return 5;

    return 0;
}