#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool uniqueOccurrences(int *arr, int arrSize) {
    int count[2001] = {0};

    // First, count the occurrences of each number
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + 1000]++;
    }

    // Second, allocate the boolean array to track which occurrences have been
    // seen, the maximum number of occurrences is arrSize
    bool *seen = (bool *)calloc(sizeof(bool) * (arrSize + 1), sizeof(bool));
    if (seen == NULL) {
        return false;
    }

    // Last, check if the number of occurrences is unique
    for (int i = 0; i < 2001; i++) {
        if (count[i] > 0) {
            if (seen[count[i]]) {
                // The number of occurrences is not unique
                free(seen);
                return false;
            }
            seen[count[i]] = true;
        }
    }

    free(seen);
    return true;
}
