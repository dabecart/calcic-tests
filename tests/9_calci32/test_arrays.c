
int main(void) {
    int arr1[4] = {1, 2, 3, 4};
    if (arr1[0] != 1 || arr1[3] != 4) return 1;

    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    if (mat[0][2] != 3) return 2;
    if (mat[1][1] != 5) return 3;

    int sum = 0;
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            sum += mat[i][j];
        }
    }
    if (sum != 21) return 4;

    return 0;
}
