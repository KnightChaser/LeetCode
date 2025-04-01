#include <stdbool.h>

#define MAX_NUMBER 1000

// Makeshift set structure for storing unique digits.
typedef struct {
    int data[MAX_NUMBER];
    int size;
} IntSet;

// Checks if athe set already contains the given element.
bool intSetContains(IntSet *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return true;
        }
    }
    return false;
}

// Adds an element to the set.
void intSetAdd(IntSet *set, int element) {
    // Insert the element only if it is not already in the set.
    if (!intSetContains(set, element)) {
        set->data[set->size] = element;
        set->size++;
    }
}

// Global array to track which 3-digit numbers have been generated
bool isNumberFound[MAX_NUMBER] = {false};

void generateNumbers(int position, int currentNumber[], bool usedDigits[],
                     int digits[], int numDigits, IntSet *uniqueNumbers) {
    // Base case: we've selected 3 digits.
    if (position == 3) {
        // Conditions:
        // - The hundreds digit (currentNumber[0]) must not be zero.
        // - The units digit (currentNumber[2]) must be even.
        if (currentNumber[0] != 0 && currentNumber[2] % 2 == 0) {
            int number = currentNumber[0] * 100 + currentNumber[1] * 10 +
                         currentNumber[2];
            intSetAdd(uniqueNumbers, number);
        }
        return;
    }

    // Recursive case: try every unused digit.
    for (int i = 0; i < numDigits; i++) {
        if (!usedDigits[i]) {
            usedDigits[i] = true; // Mark the digit as used.
            currentNumber[position] = digits[i];

            // Next position: move to the next digit.
            generateNumbers(position + 1, currentNumber, usedDigits, digits,
                            numDigits, uniqueNumbers);

            usedDigits[i] = false; // Backtrack: unmark the digit.
        }
    }
}

// Function to count unique 3-digit even numbers that can be formed.
int totalNumbers(int *digits, int numDigits) {
    int currentNumber[3] = {0}; // Store the current number being generated.
    bool usedDigits[numDigits]; // Track which digits are used.
    for (int i = 0; i < numDigits; i++) {
        usedDigits[i] = false;
    }

    IntSet uniqueNumbers; // Store the unique numbers generated.
    uniqueNumbers.size = 0;

    // Start generating numbers from position 0.
    generateNumbers(0, currentNumber, usedDigits, digits, numDigits,
                    &uniqueNumbers);

    return uniqueNumbers.size;
}
