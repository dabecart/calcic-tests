/* Test: Anonymous enum with no constants (useless and invalid syntax in some parsers if completely 
   empty, but strictly: 'enum { };' is invalid constraint). */
enum { }; // ERROR: Empty enum declaration
int main() { return 0; }