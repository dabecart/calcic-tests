char *carr = "hello reader";
/* This is invalid, the pointer can be modified as carr is not constant. The compiler should read 
carr to really know its value, therefore it's invalid.*/
char **add = &carr[5];

int main() {
    return 0;
}