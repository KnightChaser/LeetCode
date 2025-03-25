void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int len = m + n;    // The total length of the merged array (also nums1)
    int index1 = m - 1; // The last valid element of nums1
    int index2 = n - 1; // The last valid element of nums2

    // Continue while there are elements in both arrays
    for (int i = len - 1; i >= 0 && index1 >= 0 && index2 >= 0; i--) {
        // Place the greater element at the end of the merged array
        if (nums1[index1] > nums2[index2]) {
            nums1[i] = nums1[index1];
            index1--;
        } else {
            nums1[i] = nums2[index2];
            index2--;
        }
    }

    // There's a possibility that there are still elements in nums2
    while (index2 >= 0) {
        nums1[index2] = nums2[index2];
        index2--;
    }
}
