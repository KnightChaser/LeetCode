int longestOnes(int* nums, int numsSize, int k) {
    int leftIndex = 0;
    int rightIndex = 0;
    int maxConsecutiveOneCount = 0;

    for (rightIndex = 0; rightIndex < numsSize; rightIndex++) {
        if (nums[rightIndex] == 0) {
            k--;
        }

        while (k < 0) {
            // We're running out of flips, so we need to move the left index to the right
            if (nums[leftIndex] == 0) {
                k++;
            }
            // Shrink the window
            leftIndex++;
        }

        // At this point, we have a valid window
        int windowSize = rightIndex - leftIndex + 1;
        if (windowSize > maxConsecutiveOneCount) {
            maxConsecutiveOneCount = windowSize;
        }
    }

    return maxConsecutiveOneCount;
}
