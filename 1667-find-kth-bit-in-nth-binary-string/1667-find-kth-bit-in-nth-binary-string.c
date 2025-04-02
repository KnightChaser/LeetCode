#include <math.h>
#include <stdlib.h>
#include <string.h>

char *buildString(int n) {
    // Base class
    if (n == 1) {
        char *s = (char *)malloc(2 * sizeof(char));
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    // Recursively get S(n-1)
    char *previous = buildString(n - 1);
    int previousLength = (int)(pow(2, n - 1) - 1);
    int currentLength = 2 * previousLength + 1;

    // Allocate memory for the current string
    char *currentString = (char *)malloc((currentLength + 1) * sizeof(char));
    if (!currentString) {
        free(previous);
        return NULL; // Memory allocation failed
    }

    // 1. Copy s(n-1) to the first half
    strncpy(currentString, previous, previousLength);

    // 2. Append the middle bit '1'
    currentString[previousLength] = '1';

    // 3. Build into the right half, reverse(inverse(S_(n-1)))
    //    (Note that +1 for the middle bit manually appended)
    for (int i = 0; i < previousLength; i++) {
        char bit = previous[previousLength - 1 - i];
        currentString[previousLength + 1 + i] = (bit == '0') ? '1' : '0';
    }

    // Null-terminate the string
    currentString[currentLength] = '\0';

    free(previous); // Free the previous string

    return currentString;
}

char findKthBit(int n, int k) {
    char *s = buildString(n);
    char result = s[k - 1]; // k is 1-indexed, so we access s[k-1]
    free(s);                // Free the allocated string

    return result;
}
