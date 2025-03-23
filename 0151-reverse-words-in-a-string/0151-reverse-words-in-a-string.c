#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Reverse the string
void reverse(char *s, int startIndex, int endIndex) {
    while (startIndex < endIndex) {
        char temp = s[startIndex];
        s[startIndex] = s[endIndex];
        s[endIndex] = temp;
        startIndex++;
        endIndex--;
    }
}

// Normalize spaces in the string in an inplace manner
// e.g.)
//  - Input: "  hello   world!  "
//  - Output: "hello world!"
void normalizeSpaces(char *str) {
    char *read = str;
    char *write = str;
    bool isSpaceWritten = false;

    // Skip the leading spaces
    while (*read && isspace(*read)) {
        read++;
    }

    while (*read) {
        if (!isspace((unsigned char)*read)) {
            // Copy non-space characters directly
            *write++ = *read;
            isSpaceWritten = false;
        } else {
            // When encountering a space, if we haven't seen a space before,
            // copy it
            if (!isSpaceWritten) {
                *write++ = ' ';
                isSpaceWritten = true;
            }
        }
        read++;
    }

    // Remove trailing spaces
    if (write > str && isspace((unsigned char)*(write - 1))) {
        write--;
    }

    // Null-terminate the string
    *write = '\0';
}

char *reverseWords(char *s) {
    // Normalize spaces
    normalizeSpaces(s);

    // Keep track of the start of the word
    // and reverse the entire string
    int startIndex = 0;
    int endIndex = 0;
    int stringLength = strlen(s);
    reverse(s, 0, stringLength - 1);

    // Now, reverse each word
    for (int i = 0; i < stringLength; i++) {
        if (s[i] == ' ') {
            reverse(s, startIndex, endIndex - 1);
            startIndex = i + 1;
        } else if (i == stringLength - 1) {
            // If we are at the end of the string which doesn't have a space
            reverse(s, startIndex, endIndex);
        }
        endIndex++;
    }

    return s;
}
