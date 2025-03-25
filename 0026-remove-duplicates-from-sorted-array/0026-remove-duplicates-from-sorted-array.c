int removeDuplicates(int *nums, int numsSize) {
    int start = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != nums[start]) {
            // If the current number is different from the previous number,
            // increment the start index and copy the current number to the
            // start index.
            start++;
            nums[start] = nums[i];
        }
    }

    return start + 1;
}
