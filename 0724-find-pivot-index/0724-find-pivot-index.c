int pivotIndex(int *nums, int numsSize) {
    // Calculate sum of all elements
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // leftSum is totalSum - previous elements sum,
    // so we can calculate rightSum by totalSum - leftSum - nums[i]
    int leftSum = 0;
    for (int i = 0; i < numsSize; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}
