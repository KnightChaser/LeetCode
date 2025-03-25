int removeElement(int *nums, int numsSize, int val) {
    int start = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            // If the current element is not equal to the value to remove, we
            // copy it to the start of the array.
            // So we effectively remove the value from the array.
            nums[start] = nums[i];
            start++;
        }
    }

    return start;
}
