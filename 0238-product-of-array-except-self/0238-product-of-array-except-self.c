/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int *result = (int *)calloc(numsSize, sizeof(int));

    // First, fill the result array with the product of all elements to the left
    // of the current element (forward-pass)
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Second, multiply the result array with the product of all elements to the
    // suffix of the current element (backward-pass)
    int suffix = 1;
    result[numsSize - 1] = result[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        result[i] *= suffix;
    }

    *returnSize = numsSize;
    return result;
}
