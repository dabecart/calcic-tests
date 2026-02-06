/* Test: Declaring a variable with the same name as an enum type tag incorrectly. */
enum E { A };
int E; // valid
int main() {
    enum E var; 
    E = 10;
    // This is valid C. Let's make it invalid:
    // Using the variable E as a type:
    E x = 0; // ERROR: 'E' is a variable, not a type (without typedef)
    return 0;
}