void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            // Swap nums[i] and nums[lastNonZeroFoundAt]
            int tmp = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[i];
            nums[i] = tmp;

            lastNonZeroFoundAt++;
        }
    }
}
