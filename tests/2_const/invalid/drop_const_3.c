int main() {
    const int num = 10;
    const int * pointNum = &num;
    int * const pointNum2 = pointNum;
    return 0;
}