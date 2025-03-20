#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(int x) {
    char* stringified = (char*)malloc(12);
    snprintf(stringified, 12, "%d", x);

    for (int index = 0; index < strlen(stringified) / 2; index++) {
        if (stringified[index] != stringified[strlen(stringified)- index - 1]) {
            return false;
        }
    }    
    return true;
}
