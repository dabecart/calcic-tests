/* Error: Case label cannot be float */
int main() {
    int i = 1;
    switch(i) {
        case 1.0f: break; 
    }
    return 0;
}