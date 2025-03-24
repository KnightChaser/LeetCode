#include <stdlib.h>

int static compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxOperations(int *nums, int numsSize, int k) {
    // First, sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int leftIndex = 0;
    int rightIndex = numsSize - 1;
    int occurences = 0;

    while (leftIndex < rightIndex) {
        int sum = nums[leftIndex] + nums[rightIndex];
        if (sum == k) {
            // We found an exact pair.
            // We'll never use these numbers again.
            occurences++;
            leftIndex++;
            rightIndex--;
        } else if (sum < k) {
            // The current sum is too small.
            // We move left pointer +1 right to add larger number
            leftIndex++;
        } else {
            // The currnet sum is too big.
            // We move right pointer +1 left to add smaller number
            rightIndex--;
        }
    }

    return occurences;
}
