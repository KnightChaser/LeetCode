#include <stdlib.h>
#include <string.h>

char *removeStars(char *s) {
    int len = strlen(s);
    int index = 0;
    char *result = (char *)calloc(len + 1, sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] != '*') {
            // If the character is not a star, add it to the result
            // (Equivalent to pushing it to the stack)
            result[index++] = s[i];
        } else {
            // Otherwise, remove the last character from the result
            // (Equivalent to popping it from the stack)
            if (index > 0) {
                index--;
            }
        }
    }

    // Null-terminate the result
    result[index] = '\0';

    return result;
}
