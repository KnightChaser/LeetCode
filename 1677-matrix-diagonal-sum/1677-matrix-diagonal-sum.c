int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    if (*matColSize % 2 == 1) {
        for (int i = 0; i < *matColSize; i++) {
            if (i == *matColSize / 2) {
                // For middle element in odd size matrix
                // we don't want to add it twice
                sum += mat[i][i];
            } else {
                sum += mat[i][i];                   // primary diagonal sum
                sum += mat[i][*matColSize - i - 1];  // secondary diagonal sum
            }
        }
    } else {
        for (int i = 0; i < *matColSize; i++) {
            sum += mat[i][i];                   // primary diagonal sum
            sum += mat[i][*matColSize - i - 1];  // secondary diagonal sum
        }
    }

    return sum;
}
