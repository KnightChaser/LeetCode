#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

// Comparators
int compareValueDesc(const void *a, const void *b) {
    return ((Pair *)b)->value - ((Pair *)a)->value;
}

int compareIndexAsc(const void *a, const void *b) {
    return ((Pair *)a)->index - ((Pair *)b)->index;
}

int *maxSubsequence(int *nums, int numsSize, int k, int *returnSize) {
    // Build pairs
    Pair *pairs = calloc(numsSize, sizeof(Pair));
    if (!pairs) {
        perror("calloc");
        return NULL;
    }
    for (size_t i = 0; i < numsSize; i++) {
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }

    // Pick top-k by values
    qsort(pairs, numsSize, sizeof(Pair), compareValueDesc);

    // Copy out the top k pairs
    Pair *topKValues = calloc(k, sizeof(Pair));
    if (!topKValues) {
        perror("calloc");
        free(pairs);
        return NULL;
    }
    memcpy(topKValues, pairs, k * sizeof(Pair));
    free(pairs);

    // Restore the original order
    qsort(topKValues, k, sizeof(Pair), compareIndexAsc);

    // Extract the values
    int *result = calloc(k, sizeof(int));
    if (!result) {
        perror("calloc");
        free(topKValues);
        return NULL;
    }
    for (size_t i = 0; i < k; i++) {
        result[i] = topKValues[i].value;
    }

    free(topKValues);
    *returnSize = k;
    return result;
}
