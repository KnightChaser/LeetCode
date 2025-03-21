#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
    int len = strlen(s);

    // Loop through the string
    for (int subLength = 1; subLength <= len / 2; subLength++) {
        // Candidate substring must evenly divide the string
        if (len % subLength != 0) {
            continue;
        }

        // Check each substring of size subLength
        bool valid = true;
        for (int j = 0; j < len; j++) {
            if (s[j] != s[j % subLength]) {
                valid = false;
                break;
            }
        }

        // We found a valid substring
        if (valid) {
            return true;
        }
    }

    // At this point, no valid substring was found
    return false;
}
