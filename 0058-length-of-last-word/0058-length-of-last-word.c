#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    // Right trim the space
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            // If it's space, replace it with '\0'(NULL)
            s[i] = '\0';
        } else {
            break;
        }
    }

    // Find the last space in the string, and +1 to get the last word
    char *lastSpace = strrchr(s, ' ');
    char *lastWord = lastSpace == NULL ? s : lastSpace + 1;

    // Count the length of the last word, except the space
    int length = 0;
    for (int i = 0; lastWord[i] != '\0'; i++) {
        if (lastWord[i] != ' ') {
            length++;
        }
    }

    return length;
}
