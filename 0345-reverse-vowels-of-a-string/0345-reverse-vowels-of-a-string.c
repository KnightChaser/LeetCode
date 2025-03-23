#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isCharacterVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char *reverseVowels(char *s) {
    int frontIndex = 0;
    int backIndex = strlen(s) - 1;

    char *result = (char *)calloc(strlen(s) + 1, sizeof(char));
    strncpy(result, s, strlen(s));

    while (frontIndex < backIndex) {
        if (isCharacterVowel(result[frontIndex]) &&
            isCharacterVowel(result[backIndex])) {
            // At this moment, both characters at the front and back indices are
            // Swap the characters at the front and back indices
            char temp = result[frontIndex];
            result[frontIndex] = result[backIndex];
            result[backIndex] = temp;
            frontIndex++;
            backIndex--;
        }

        if (!isCharacterVowel(result[frontIndex])) {
            // If the character at the front index is not a vowel, move to the
            // next character
            frontIndex++;
        }

        if (!isCharacterVowel(result[backIndex])) {
            // If the character at the back index is not a vowel, move to the
            // previous character
            backIndex--;
        }
    }
    return result;
}
