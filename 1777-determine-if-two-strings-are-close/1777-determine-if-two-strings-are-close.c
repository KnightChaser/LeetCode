#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool closeStrings(char *word1, char *word2) {
    int word1len = strlen(word1);
    int word2len = strlen(word2);
    if (word1len != word2len) {
        // If the length of word1 and word2 are not the same,
        // Those two are never considered "close"
        return false;
    }
    if (strncmp(word1, word2, word1len) == 0) {
        // If word1 and word2 are the same,
        // they are indeed called "close"
        return true;
    }

    // Hash table to store the frequency of each character in word1 and word2
    int count1[26] = {0}, count2[26] = {0};

    // Count the frequency of each character in word1 and word2
    for (int i = 0; i < word1len; i++) {
        count1[word1[i] - 'a']++;
    }
    for (int i = 0; i < word2len; i++) {
        count2[word2[i] - 'a']++;
    }

    // If there is an alphabet in word1 that is not in word2, return false
    for (int i = 0; i < 26; i++) {
        if (count1[i] == 0 && count2[i] != 0) {
            return false;
        }
    }

    // If count1(word1's frequency) and count2(word2's frequency) are not the
    // same, return false. We can sort the frequency arrays and compare them
    qsort(count1, 26, sizeof(int), compare);
    qsort(count2, 26, sizeof(int), compare);
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}
