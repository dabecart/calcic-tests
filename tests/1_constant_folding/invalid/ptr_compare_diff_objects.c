/* Undefined Behavior: Comparing pointers to different objects.
   Relational operators (<, >, <=, >=) are only valid within the same object.
*/
int a;
int b;
int cmp = &a < &b; /* Error or Warning treated as error */
int main() { return 0; }