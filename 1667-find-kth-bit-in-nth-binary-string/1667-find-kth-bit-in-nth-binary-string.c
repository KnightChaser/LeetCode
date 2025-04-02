#include <math.h>

char findKthBit(int n, int k) {
    // Base case: S_1 = "0"
    if (n == 1) {
        return '0';
    }

    int stringLength = pow(2, n) - 1;
    int middleIndex = (stringLength / 2) + 1;

    // Exactly hit the middle index
    if (k == middleIndex) {
        return '1';
    }

    // If k is in the first half,
    // continue searching in the first half
    if (k < middleIndex) {
        return findKthBit(n - 1, k);
    }

    // If k is in the second half,
    // since the second half is the reverse of the first half,
    // continue searching in the first half. But,
    // - Reverse the index
    // - Reverse the character bit
    if (k > middleIndex) {
        int reverseIndex = stringLength - k + 1; // +1 because of 1-based index
        char result = findKthBit(n - 1, reverseIndex);
        return (result == '0') ? '1' : '0';
    }

    // unreachable
    return '0';
}
