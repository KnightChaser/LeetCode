#include <stdbool.h>

int longestSubarray(int *nums, int numsSize) {
    int leftIndex = 0;
    int rightIndex = 0;
    int maxSubarrayLength = 0;
    int k = 1; // Number of zeros allowed

    for (rightIndex = 0; rightIndex < numsSize; rightIndex++) {
        if (nums[rightIndex] == 0) {
            k--;
        }

        while (k < 0) {
            // We have more than k zeros in the subarray
            if (nums[leftIndex] == 0) {
                k++;
            }
            // Slide the window to the right
            leftIndex++;
        }

        // At this point, we have at most k zeros in the subarray
        int subarrayLength = rightIndex - leftIndex + 1;
        if (subarrayLength > maxSubarrayLength) {
            maxSubarrayLength = subarrayLength;
        }
    }

    // We need to exclude the zero which was added to the subarray
    maxSubarrayLength -= 1;

    return maxSubarrayLength;
}
