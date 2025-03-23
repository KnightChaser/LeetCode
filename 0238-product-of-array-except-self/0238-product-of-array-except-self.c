/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    // It's okay not to use calloc() here because we're going to fill the array
    // so it'll help us to avoid unnecessary overhead
    int *result = (int *)malloc(sizeof(int) * numsSize);

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
