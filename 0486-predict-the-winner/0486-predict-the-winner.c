#include <stdbool.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

bool predictTheWinner(int *nums, int numsSize) {
    // Create a n by n DP table
    int **dp = (int **)malloc(numsSize * sizeof(int *));
    for (size_t i = 0; i < numsSize; i++) {
        dp[i] = (int *)malloc(numsSize * sizeof(int));
    }

    // Base case: when there is only one number,
    // the player must take that one
    for (size_t i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
    }

    // Build up the DP table
    for (size_t len = 2; len <= numsSize; len++) {
        for (size_t i = 0; i + len - 1 < numsSize; i++) {
            int j =
                i + len - 1; // index of the last number in the current range
            int takeLeft = nums[i] - dp[i + 1][j];  // take the left number
            int takeRight = nums[j] - dp[i][j - 1]; // take the right number
            dp[i][j] = max(takeLeft, takeRight);    // choose the best option
        }
    }

    bool result = dp[0][numsSize - 1] >= 0; // check if the first player can win

    // Clean up the DP table
    for (size_t i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
