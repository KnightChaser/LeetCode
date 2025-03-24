#include <stdbool.h>

bool isSubsequence(char *s, char *t) {
    // Is "s" is a binary subsequence of "t"?
    int sIndex = 0;
    int tIndex = 0;

    while (s[sIndex] != '\0' && t[tIndex] != '\0') {
        if (s[sIndex] == t[tIndex]) {
            sIndex++;
        }
        tIndex++;
    }

    // if sIndex is equal to the length of s, then s is a subsequence of t
    // because we found all the characters of s in t
    return s[sIndex] == '\0';
}
