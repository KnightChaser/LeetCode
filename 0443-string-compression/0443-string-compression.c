#include <stdio.h>
#include <stdlib.h>

// Convert an integer to a string
char *integerToString(int n) {
    // Considering 1 <= chars.length <= 2000
    char *str = (char *)calloc(5, sizeof(char));
    sprintf(str, "%d", n);
    return str;
}

int compress(char *chars, int charsSize) {
    int i = 0;
    int writeIndex = 0;

    while (i < charsSize) {
        char currentChar = chars[i];
        int count = 0;

        // Count the occurrence of the current character
        // The same consecutive characters are counted as one occurrence
        while (i < charsSize && chars[i] == currentChar) {
            i++;
            count++;
        }

        // Write the current character
        chars[writeIndex] = currentChar;
        writeIndex++;

        // If count(the number of occurrence of the current character) is
        // greater than 1, write the coun t
        if (count > 1) {
            char *numStr = integerToString(count);
            for (int j = 0; numStr[j] != '\0'; j++) {
                // Insert stringified integer char by char
                chars[writeIndex] = numStr[j];
                writeIndex++;
            }
            free(numStr);
        }
    }

    return writeIndex;
}
