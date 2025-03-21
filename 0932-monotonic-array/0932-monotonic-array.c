#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    bool monotonic = true;
    
    // Determine the direction of the array
    bool increasing = nums[0] <= nums[numsSize-1];

    // Now, iterate through the array and check if the direction is maintained
    for (int i = 1; i < numsSize; i++) {
        // We pass if two adjacent elements are equal
        if (nums[i-1] == nums[i]) {
            continue;
        }
        
        if (increasing) {
            // Assume monotonic increment
            if (nums[i-1] > nums[i]) {
                // But it's strictly decreasing
                monotonic = false;
                break;
            }
        } else {
            // Assume monotonic decrement
            if (nums[i-1] < nums[i]) {
                // But it's strictly increasing
                monotonic = false;
                break;
            }
        }

        // DEBUG
        // printf("i: %d, increasing: %d, nums[i-1]: %d, nums[i]: %d\n", i, increasing, nums[i-1], nums[i]);
    }

    return monotonic;
}
