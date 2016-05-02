int func(int** mat, int colCount, int rowCount) {
    int r = rowCount;
    int c = colCount;
    for (int i = 1; i < r; ++i) {
        mat[i][0] = min(mat[i][0], mat[i - 1][0]);
    }
    for (int i = 1; i < c; ++i) {
        mat[0][j] = min(mat[0][j], mat[0][j - 1]);
    }
    for (int i = 1; i < r; ++i) {
        for (int j = 1; j < c; ++j) {
            int tmp1 = min(mat[i][j], mat[i][j-1]);
            int tmp2 = min(mat[i][j], mat[i - 1][j]);
            mat[i][j] = max(tmp1, tmp2);
        }
    }
    return mat[r - 1][c - 1];
}
