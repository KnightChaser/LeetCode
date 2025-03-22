#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) { return a > b ? a : b; }

char *addBinary(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = max(lenA, lenB);

    // Allocate the memory for the result
    // - +1 for the carry
    // - +1 for the null terminator
    char *result = (char *)malloc(maxLen + 2);
    if (result == NULL) {
        return NULL;
    }
    result[maxLen + 1] = '\0'; // The null terminator

    int carry = 0;
    int sumBit, aBit, bBit;
    int i = lenA - 1;
    int j = lenB - 1;
    int position = maxLen + 1; // Position of the current bit in the result

    // Proces>s the bits from the LSB(Less Significant Bit) to
    // the MSB(Most Significant Bit)
    while (i >= 0 || j >= 0 || carry) {
        aBit = i >= 0 ? a[i] - '0'
                      : 0; // If there is a bit in a, get it, otherwise, use 0
        bBit = j >= 0 ? b[j] - '0'
                      : 0; // If there is a bit in b, get it, otherwise, use 0
        sumBit = aBit + bBit + carry; // Calculate the sum of the current bits
        carry = sumBit / 2;           // carry is 1 if sumBit is 2 or 3

        position--;
        result[position] =
            sumBit % 2 + '0'; // Store the current bit in the result
        i--;
        j--;
    }

    return result + position; // Return the result
                              // +position is used to skip the leading zeros
}
