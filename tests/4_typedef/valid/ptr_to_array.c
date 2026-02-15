// Exit code: 0
typedef int Arr3[3];
typedef Arr3 * ArrPtr;

int main(void) {
    Arr3 data = {10, 20, 30};
    ArrPtr p = &data;
    if ((*p)[2] != 30) return 1;
    return 0;
}