#include <stdbool.h>

int arraySign(int* nums, int numsSize) {
    // Check if 0 is contained in the array.
    // If at least one 0 is contained, the product will be 0,
    // Thus, the sign will be 0.
    bool isZeroContained = false;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            isZeroContained = true;
            break;
        }
    }
    
    if (isZeroContained) {
        return 0;
    }

    // If not, we simply count the number of negative numbers.
    // If the number of negative numbers is even, the product will be positive.
    int negativeCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            negativeCount++;
        }
    }

    return negativeCount % 2 == 0 ? 1 : -1;
}
