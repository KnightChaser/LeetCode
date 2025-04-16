#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

static int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minimumDifference(int *nums, int numsSize, int k) {
    // Base case: if there is only one element, return 0
    if (numsSize == 1) {
        return 0;
    }

    // First, compute the sum of the first k elements
    qsort(nums, numsSize, sizeof(int), compare);

    // Second, calculate the minimum gap within the sliding window of size k
    int gap;
    int minGap = 100000; // 10^5
    for (size_t i = 0; i < numsSize - k + 1; i++) {
        // Update the minimum gap if the current gap is smaller
        gap = nums[i + k - 1] - nums[i];
        minGap = min(minGap, gap);
        if (gap < 0) {
            return 0;
        }
    }

    return minGap;
}
