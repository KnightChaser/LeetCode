#include <stdlib.h>

int static compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int largestPerimeter(int *nums, int numsSize) {
    // Sort the nums array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    // To form a triangle, let's say the sides are a, b, c
    // Then, len(a) + len(b) > len(c) should be true
    for (int i = numsSize - 1; i >= 2; i--) {
        if (nums[i - 2] + nums[i - 1] > nums[i]) {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }

    // If no such triangle exists, return 0
    return 0;
}
