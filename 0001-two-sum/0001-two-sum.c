/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h> // to use qsort()

typedef struct {
    int value;
    int index;
} Pair;

// Compare two Pair struct with its values
int comparePair(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;
    return p1->value > p2->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Store the values of `nums` into Pair[]
    Pair pairs[numsSize];
    for (int index = 0; index < numsSize; index++) {
        pairs[index].value = nums[index];
        pairs[index].index = index;
    }

    // O(n lg n) (using QuickSort)
    qsort(pairs, numsSize, sizeof(Pair), comparePair);

    // for (int index = 0; index < numsSize; index++) {
    //     printf("pairs[%d] => %d\n", pairs[index].index, pairs[index].value);
    // }

    int leftIndex = 0;
    int rightIndex = numsSize - 1;
    while (leftIndex < rightIndex) {
        int leftRightSum = pairs[leftIndex].value + pairs[rightIndex].value;
        if (leftRightSum == target) {
            // We found the solution
            *returnSize = 2;
            int* resultArray = (int*)malloc(sizeof(int) * 2);
            resultArray[0] = pairs[leftIndex].index;
            resultArray[1] = pairs[rightIndex].index;
            return resultArray;
        } else if (leftRightSum < target) {
            // The leftRightSum value is currently less than target.
            // We have to move the leftIndex to right to add bigger number
            leftIndex++;
        } else {
            // The leftRightSum value is currently more than target.
            // We have to move the rightIndex to left to add smaller number
            rightIndex--;
        }
    }

    // Unreachable according to the problem statement
    *returnSize = 1;
    int dummy = 0;
    return &dummy;
}