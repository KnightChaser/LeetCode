#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool uniqueOccurrences(int *arr, int arrSize) {
    int count[2001] = {0};

    // First, count the occurrences of each number
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + 1000]++;
    }

    // Second, count the occurrences of each occurrence
    //         by sorting the occurrences of each number,
    //         if two adjacent numbers are the same, it means duplicity.
    qsort(count, 2001, sizeof(int), compare);
    for (int i = 1; i < 2001; i++) {
        if (count[i] == count[i - 1] && count[i] != 0) {
            return false;
        }
    }

    return true;
}
