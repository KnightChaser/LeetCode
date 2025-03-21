#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);
    int expectedSubstringLength = 1;
    bool hasSubstringPattern = false;

    for (int i = 0; i < len / 2; i++) {
        // We must ensure that the length of the substring is a factor of the length of the string
        while (len % expectedSubstringLength != 0 && expectedSubstringLength < len / 2) {
            expectedSubstringLength++;
        }
        // printf("Expected substring length: %d\n", expectedSubstringLength);

        // Reset the flag
        hasSubstringPattern = false;

        // The possible substring can be from 1 to len / 2
        for (int j = 0; j < len; j += expectedSubstringLength) {
            // We will check if the substring is repeated
            if (strncmp(s, s + j, expectedSubstringLength) == 0) {
                hasSubstringPattern = true;
            } else {
                hasSubstringPattern = false;
                break;
            }
            // printf("Substring: %.*s, hasSubstringPattern: %s\n", expectedSubstringLength, s + j, hasSubstringPattern ? "true" : "false");
        }

        // If we found a substring pattern, we can return true
        if (hasSubstringPattern) {
            return true;
        }

        expectedSubstringLength++;
    }

    return hasSubstringPattern;
}
