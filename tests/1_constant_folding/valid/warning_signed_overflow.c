// Exit code: 0

/* Signed integer overflow in constant expressions is Undefined Behavior.
   Strict C compilers often reject this. calcic gives out a warning. */
#include <limits.h>
int x = INT_MAX + 1;
int main() { 
   return x == -2147483648 ? 0 : 1; 
}