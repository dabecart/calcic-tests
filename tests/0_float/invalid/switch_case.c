/* Error: Case label cannot be float */
void test() {
    int i = 1;
    switch(i) {
        case 1.0f: break; 
    }
}