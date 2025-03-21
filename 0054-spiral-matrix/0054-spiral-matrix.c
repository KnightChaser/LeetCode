/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int row = matrixSize;
    int col = matrixColSize[0];

    // Track which positions we've visited so far
    int leftVisitedIndex = 0;
    int rightVisitedIndex = col - 1;
    int topVisitedIndex = 0;
    int bottomVisitedIndex = row - 1;

    int* result = (int*)malloc(sizeof(int) * row * col);
    memset(result, 0, sizeof(int) * row * col);
    *returnSize = 0;

    // Go spirally
    while (leftVisitedIndex <= rightVisitedIndex && topVisitedIndex <= bottomVisitedIndex) {
        // First, go right
        for (int i = leftVisitedIndex; i <= rightVisitedIndex; i++) {
            result[*returnSize] = matrix[topVisitedIndex][i];
            (*returnSize)++;
        }
        topVisitedIndex++;

        // Second, go down (also check if we can still go down)
        if (topVisitedIndex <= bottomVisitedIndex) {
            for (int i = topVisitedIndex; i <= bottomVisitedIndex; i++) {
                result[*returnSize] = matrix[i][rightVisitedIndex];
                (*returnSize)++;
            }
            rightVisitedIndex--;
        }

        // Third, go left (also check if we can still go left)
        if (leftVisitedIndex <= rightVisitedIndex && topVisitedIndex <= bottomVisitedIndex) {
            for (int i = rightVisitedIndex; i >= leftVisitedIndex; i--) {
                result[*returnSize] = matrix[bottomVisitedIndex][i];
                (*returnSize)++;
            }
            bottomVisitedIndex--;
        }

        // Fourth, go up
        if (leftVisitedIndex <= rightVisitedIndex && topVisitedIndex <= bottomVisitedIndex && topVisitedIndex <= bottomVisitedIndex) {
            for (int i = bottomVisitedIndex; i >= topVisitedIndex; i--) {
                result[*returnSize] = matrix[i][leftVisitedIndex];
                (*returnSize)++;
            }
            leftVisitedIndex++;
        }
    }

    return result;
}
