#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(int *)a == 0) {
        return 1;
    } else {
        return -1;
    }
}

void moveZeroes(int* nums, int numsSize) {
    // First, sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    // Then, move all the zeroes to the end of the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            int tmp = nums[numsSize - 1];
            nums[numsSize - 1] = nums[i];
            nums[i] = tmp;
        }
    }

    return;
}
