double max(double a, double b) { return a > b ? a : b; }

double findMaxAverage(int *nums, int numsSize, int k) {
    double sum = 0;
    double maxSum = 0;

    // First, we calculate the sum of the first k elements.
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    maxSum = sum;

    // Next, we calculate the sum of the next k elements by sliding the window.
    // If we increase index by 1, we add the next element and subtract the first
    // element.
    for (int i = k; i < numsSize; i++) {
        sum += nums[i] - nums[i - k];
        maxSum = max(maxSum, sum);
    }

    return maxSum / k;
}
