double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
    int* mergedArray = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));

    // Merge the two integer arrays
    int currNums1Index = 0;
    int currNums2Index = 0;
    int currMergedArrayIndex = 0;
    while (currNums1Index < nums1Size && currNums2Index < nums2Size) {
        if (nums1[currNums1Index] <= nums2[currNums2Index]) {
            // Smaller one comes first
            mergedArray[currMergedArrayIndex] = nums1[currNums1Index];
            currNums1Index++;
            currMergedArrayIndex++;
        } else {
            mergedArray[currMergedArrayIndex] = nums2[currNums2Index];
            currNums2Index++;
            currMergedArrayIndex++;
        }
    }

    // Copy the remaining ones
    while (currNums1Index < nums1Size) {
        mergedArray[currMergedArrayIndex] = nums1[currNums1Index];
        currMergedArrayIndex++;
        currNums1Index++;
    }

    while (currNums2Index < nums2Size) {
        mergedArray[currMergedArrayIndex] = nums2[currNums2Index];
        currMergedArrayIndex++;
        currNums2Index++;
    }

    // Calculate the median value
    int arraySize = (nums1Size + nums2Size);
    int index = arraySize - 1; // Arrays start with 0
    if (arraySize % 2 == 1) {
        return (double)(mergedArray[index / 2]);
    } else {
        return ((double)mergedArray[index / 2] +
                (double)mergedArray[(index / 2) + 1]) /
               2;
    }

    return 0;
}