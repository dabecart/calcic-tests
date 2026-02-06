/* Test: Forward declaration of enum (invalid in standard C, though valid in some extensions). 
   We test the standard behavior. */
enum E; // ERROR: ISO C forbids forward references to 'enum' types
int main() { return 0; }