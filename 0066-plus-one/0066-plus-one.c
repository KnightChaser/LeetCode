#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Check the edge case such as 9, 99, 999, 9999 
    bool isAllNine = true;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            isAllNine = false;
            break;
        }
    }

    // Create a new array to store the result
    int resultArraySize;
    if (isAllNine) {
        // We need to carry the 1 to the next digit
        resultArraySize = digitsSize + 1;
    } else {
        resultArraySize = digitsSize;   
    }
    int* resultArray = (int*)malloc(resultArraySize * sizeof(int));
    memset(resultArray, 0, resultArraySize * sizeof(int));
    *returnSize = resultArraySize;

    // Copy the original array to the result array, from back to front
    for (int i = digitsSize - 1; i >= 0; i--) {
        resultArray[i] = digits[i];
    }

    // Add 1 to the last digit.
    // We have to move the carry to the next digit if the last digit is 9
    int carry = 0;
    int currentIndex = digitsSize - 1;
    do {
        resultArray[currentIndex] += 1;
        if (resultArray[currentIndex] == 10) {
            resultArray[currentIndex] = 0;
            carry = 1;
            currentIndex--;
        } else {
            carry = 0;
        }
    } while (carry == 1 && currentIndex >= 0);

    if (carry == 1) {
        resultArray[0] = 1;
    }

    return resultArray;
}
