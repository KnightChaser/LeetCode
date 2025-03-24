#include <stdbool.h>
#include <string.h>

// We only consider lowercase English letters
bool isCharVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int max(int a, int b) { return a > b ? a : b; }

int maxVowels(char *s, int k) {
    int maxVowelCounts = 0;
    int currentVowelCounts = 0;

    // First substring
    for (int i = 0; i < k; i++) {
        if (isCharVowel(s[i])) {
            currentVowelCounts++;
        }
    }
    maxVowelCounts = currentVowelCounts;

    // We only need to consider the index which can form a substring of length k
    for (int i = k; i < strlen(s); i++) {

        // If the added character is a vowel
        if (isCharVowel(s[i])) {
            currentVowelCounts++;
        }

        // If the removed character is a vowel
        if (isCharVowel(s[i - k])) {
            currentVowelCounts--;
        }

        maxVowelCounts = max(maxVowelCounts, currentVowelCounts);
    }

    return maxVowelCounts;
}
