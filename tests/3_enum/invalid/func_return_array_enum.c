/* Test: Function returning array of enums (not allowed in C). */
enum E { A };
enum E func()[5] { // ERROR: Function cannot return array
    return 0;
}
int main() { return 0; }