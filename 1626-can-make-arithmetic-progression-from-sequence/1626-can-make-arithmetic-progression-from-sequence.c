#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    // Sort the array
    qsort(arr, arrSize, sizeof(int), compare);

    // Measure the distance between the first two elements
    int gap = arr[1] - arr[0];

    // Iterate through the array to check if the gap is consistent
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != gap) {
            return false;
        }
    }

    // We have a consistent gap
    return true;
}
