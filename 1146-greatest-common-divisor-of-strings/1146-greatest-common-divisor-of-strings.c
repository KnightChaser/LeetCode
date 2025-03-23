#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *gcdOfStrings(char *str1, char *str2) {
    // Given two strings str1 and str2,
    // return the largest string x such that x divides both str1 and str2.
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    char *maxStrGcd = "";

    for (int i = 1; i <= str1len && i <= str2len; i++) {
        if (str1len % i == 0 && str2len % i == 0) {
            // The gcd of two strings is a prefix of both string
            char *subStr = (char *)calloc(i + 1, sizeof(char));
            strncpy(subStr, str1, i);

            // Test if the prefix is a gcd of the two strings (str1 and str2)
            bool isGcd = true;
            for (int j = 0; j < str1len; j++) {
                if (str1[j] != subStr[j % i]) {
                    isGcd = false;
                    break;
                }
            }

            for (int j = 0; j < str2len; j++) {
                if (str2[j] != subStr[j % i]) {
                    isGcd = false;
                    break;
                }
            }

            // If the prefix is a gcd of the two strings (str1 and str2),
            // Update the maxStrGcd
            if (isGcd) {
                maxStrGcd = subStr;
            }
        }
    }

    return maxStrGcd;
}
