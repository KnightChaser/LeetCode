#include <stdbool.h>
#include <stdlib.h>

int equalPairs(int **grid, int gridSize, int *gridColSize) {
    int count = 0;
    bool isPair = false;

    // We'll store the row and column values in separate arrays
    int *row = (int *)malloc(gridSize * sizeof(int));
    int *col = (int *)malloc(gridSize * sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            // Inspect the current row and column
            isPair = true;

            // Store the row and column values into the *row and *col
            for (int k = 0; k < gridSize; k++) {
                row[k] = grid[i][k];
                col[k] = grid[k][j];
            }

            // Check if the row and column values are equal
            for (int k = 0; k < gridSize; k++) {
                if (row[k] != col[k]) {
                    isPair = false;
                    break;
                }
            }

            if (isPair) {
                count++;
            }
        }
    }

    free(row);
    free(col);

    return count;
}
