#include <stdlib.h>

int pivotIndex(int *nums, int numsSize) {
    int *leftPrefixSum = (int *)calloc(numsSize, sizeof(int));
    int *rightPrefixSum = (int *)calloc(numsSize, sizeof(int));

    // Calculate left prefix sum
    leftPrefixSum[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        leftPrefixSum[i] = leftPrefixSum[i - 1] + nums[i];
    }

    // Calculate right prefix sum
    rightPrefixSum[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        rightPrefixSum[i] = rightPrefixSum[i + 1] + nums[i];
    }

    // Now, check if there is any pivot index
    int pivotIndex = -1;
    for (int i = 0; i < numsSize; i++) {
        if (leftPrefixSum[i] == rightPrefixSum[i]) {
            pivotIndex = i;
            break;
        }
    }

    return pivotIndex;
}
