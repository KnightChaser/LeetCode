#include <stdbool.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int predictTheWinnerHelper(int nums[], int i, int j) {
    if (i == j) {
        // Only one number left.
        // In this case, the player can only take that number.
        return nums[i];
    }

    // If I take nums[i], the opponent then plays optimally on [i+1, j]
    int takeLeft = nums[i] - predictTheWinnerHelper(nums, i + 1, j);

    // If I take nums[j], the opponent then plays optimally on [i, j-1]
    int takeRight = nums[j] - predictTheWinnerHelper(nums, i, j - 1);

    return max(takeLeft, takeRight);
}

bool predictTheWinner(int *nums, int numsSize) {
    // If it returns a non-negative value,
    // it means the first player can win or tie.
    return predictTheWinnerHelper(nums, 0, numsSize - 1) >= 0;
}
