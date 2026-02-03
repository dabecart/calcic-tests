/* Undefined Behavior (usually Error in static analysis):
   Subtracting pointers to different objects.
   The compiler cannot know the relative distance between 'a' and 'b' at compile time
   because the linker decides their placement.
*/
int a;
int b;
long diff = &a - &b; /* Error: Not a constant expression */
int main() { return 0; }