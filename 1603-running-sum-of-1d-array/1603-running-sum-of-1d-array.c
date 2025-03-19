/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int currentSum = 0;
    int* sumArray = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int index = 0; index < numsSize; index++) {
        currentSum += nums[index];
        sumArray[index] = currentSum;
    }

    return sumArray;
}