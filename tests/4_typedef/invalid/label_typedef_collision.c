// Valid in C (labels have own namespace), but let's test a syntax error involving labels
// Error: label used as type
int main(void) {
    label: ;
    label x; // Syntax error
    return 0;
}