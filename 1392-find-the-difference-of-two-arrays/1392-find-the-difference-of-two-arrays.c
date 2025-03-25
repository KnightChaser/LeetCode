/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>

#define SET_OFFSET 1000 // to handle -1000 ~ 1000
#define SET_SIZE 2001   // -1000 ~ 1000

int **findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size,
                     int *returnSize, int **returnColumnSizes) {
    bool set1[SET_SIZE] = {false};
    bool set2[SET_SIZE] = {false};

    // Fill sets
    for (int i = 0; i < nums1Size; i++) {
        set1[nums1[i] + SET_OFFSET] = true;
    }

    for (int i = 0; i < nums2Size; i++) {
        set2[nums2[i] + SET_OFFSET] = true;
    }

    // Measure the number of different elements each other
    int set1DiffSize = 0;
    int set2DiffSize = 0;
    for (int i = 0; i < SET_SIZE; i++) {
        if (set1[i] && !set2[i]) {
            set1DiffSize++;
        }
        if (set2[i] && !set1[i]) {
            set2DiffSize++;
        }
    }

    // Create an answer
    // A little bit complicated because of the return type
    int **answer = (int **)calloc(2 * sizeof(int *), sizeof(int *));
    answer[0] = (int *)calloc(set1DiffSize * sizeof(int), sizeof(int));
    answer[1] = (int *)calloc(set2DiffSize * sizeof(int), sizeof(int));

    *returnColumnSizes = (int *)calloc(2 * sizeof(int), sizeof(int));
    (*returnColumnSizes)[0] = set1DiffSize;
    (*returnColumnSizes)[1] = set2DiffSize;

    *returnSize = 2;

    // Fill the answer arrays with the distinct elements
    int index = 0;
    for (int i = 0; i < SET_SIZE; i++) {
        if (set1[i] && !set2[i]) {
            answer[0][index] = i - SET_OFFSET;
            index++;
        }
    }

    index = 0;
    for (int i = 0; i < SET_SIZE; i++) {
        if (set2[i] && !set1[i]) {
            answer[1][index] = i - SET_OFFSET;
            index++;
        }
    }

    return answer;
}
