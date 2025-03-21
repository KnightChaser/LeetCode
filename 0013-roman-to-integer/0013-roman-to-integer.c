#include <string.h>

int romanToInt(char *s) {
    // Convert Roman to Integer
    // I = 1
    // V = 5
    // X = 10
    // L = 50
    // C = 100
    // D = 500
    // M = 1000
    // Exception: IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900

    int len = strlen(s);
    int number = 0;
    for (int i = 0; i < len; i++) {
        // Check for exceptions
        if (strncmp(s + i, "CM", 2) == 0) {
            number += 900;
            i++; // Because we have already checked 2 characters
        } else if (strncmp(s + i, "CD", 2) == 0) {
            number += 400;
            i++;
        } else if (strncmp(s + i, "XC", 2) == 0) {
            number += 90;
            i++;
        } else if (strncmp(s + i, "XL", 2) == 0) {
            number += 40;
            i++;
        } else if (strncmp(s + i, "IX", 2) == 0) {
            number += 9;
            i++;
        } else if (strncmp(s + i, "IV", 2) == 0) {
            number += 4;
            i++;
        } else {
            // Go through the ordinary cases
            switch (s[i]) {
            case 'M':
                number += 1000;
                break;
            case 'D':
                number += 500;
                break;
            case 'C':
                number += 100;
                break;
            case 'L':
                number += 50;
                break;
            case 'X':
                number += 10;
                break;
            case 'V':
                number += 5;
                break;
            case 'I':
                number += 1;
                break;
            default:
                break;
            }
        }
    }

    return number;
}
