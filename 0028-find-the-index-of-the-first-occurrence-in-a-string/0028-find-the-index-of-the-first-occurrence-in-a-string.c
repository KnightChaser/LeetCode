#include <stdbool.h>

int strStr(char* haystack, char* needle) {
    int occurrenceIndex = -1;
    char* occurrence = NULL;

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            // If the first character of the needle is found in the haystack
            // We will check if the rest of the needle is in the haystack
            occurrence = &haystack[i];
            int tmp = i;
            bool needleFound = true;

            for (int j = 0; needle[j] != '\0'; j++) {
                // printf("haystack[%d + %d] = %c, needle[%d] = %c\n", i, j, haystack[i + j], j, needle[j]);
                if (haystack[i + j] != needle[j]) {
                    // If the characters don't match, we break the loop
                    occurrence = NULL;
                    needleFound = false;
                    break;
                }
            }

            // No need to continue if we found the needle.
            // But if we didn't check the rest of the haystack, we will continue
            if (needleFound) {
                occurrenceIndex = tmp;
                break;
            }
        }
    }

    return occurrenceIndex;
}
