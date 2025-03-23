/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>

// Among the given candies, find the maximum number of candies
int getMax(int *candies, int candiesSize) {
    int max = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    return max;
}

bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize) {
    bool *flags = (bool *)calloc(candiesSize, sizeof(bool));
    *returnSize = candiesSize;
    int currentMaxCandies = getMax(candies, candiesSize);

    for (int i = 0; i < candiesSize; i++) {
        // Find out if the current kid can have the maximum number of candies
        if (candies[i] + extraCandies < currentMaxCandies) {
            // The current kid can't have the maximum number of candies
            flags[i] = false;
        } else {
            // Otherwise
            flags[i] = true;
        }
    }

    return flags;
}
