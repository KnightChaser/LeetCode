#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int row = matrixSize;
    int col = *matrixColSize;
    
    // Mark the first row and first column has zero
    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    for (int j = 0; j < col; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // Traverse the matrix and mark the rows and columns that are to be set to zero
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set the rows and columns to zero
    // 1. Set the rows to zero
    for (int i = 1; i < row; i++) {
        if (matrix[i][0] == 0) {
            // If there is a zero in the first column, set the entire row to zero
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // 2. Set the columns to zero
    for (int j = 1; j < col; j++) {
        if (matrix[0][j] == 0) {
            // If there is a zero in the first row, set the entire column to zero
            for (int i = 0; i < row; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Finally, set the first row and first column to zero if necessary
    if (firstRowHasZero) {
        for (int j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (int i = 0; i < row; i++) {
            matrix[i][0] = 0;
        }
    }
}
