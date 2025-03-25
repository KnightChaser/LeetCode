// Using binary search to find the target in the sorted array
int searchInsert(int *nums, int numsSize, int target) {
    int lowIndex = 0;
    int highIndex = numsSize - 1;
    int midIndex;

    while (lowIndex <= highIndex) {
        midIndex = (lowIndex + highIndex) / 2;

        if (nums[midIndex] == target) {
            // If the target is found, return the index
            return midIndex;
        } else if (nums[midIndex] < target) {
            // If the target is greater than the middle element,
            // search the right half for smaller elements
            lowIndex = midIndex + 1;
        } else if (nums[midIndex] > target) {
            // If the target is smaller than the middle element,
            // search the left half for greater elements
            highIndex = midIndex - 1;
        }
    }

    return lowIndex;
}
