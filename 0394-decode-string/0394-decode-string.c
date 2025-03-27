#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 100
#define STRING_BUFFER_SIZE 1024

// ---- Integer Stack ----

typedef struct {
    int *data;
    int top;
    int capacity;
} IntStack;

// Create and initialize an integer stack
IntStack *createIntStack(int capacity) {
    IntStack *stack = (IntStack *)malloc(sizeof(IntStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int *)malloc(capacity * sizeof(int));
    return stack;
}

// Push an integer onto the stack
void pushIntStack(IntStack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->data =
            (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

// Pop an integer from the stack
int popIntStack(IntStack *stack) {
    if (stack->top == -1) {
        fprintf(stderr, "IntStack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Free the integer stack
void freeIntStack(IntStack *stack) {
    free(stack->data);
    free(stack);
}

typedef struct {
    char **data;
    int top;
    int capacity;
} StringStack;

// ---- String Stack ----

StringStack *createStringStack(int capacity) {
    StringStack *stack = (StringStack *)malloc(sizeof(StringStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char **)malloc(capacity * sizeof(char *));
    return stack;
}

// Push a string onto the stack (make a copy of the string)
void pushStringStack(StringStack *stack, const char *str) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->data =
            (char **)realloc(stack->data, stack->capacity * sizeof(char *));
    }
    stack->data[++stack->top] = strdup(str);
}

// Pop a string from the stack (caller must free the returned string when done)
char *popStringStack(StringStack *stack) {
    if (stack->top == -1) {
        fprintf(stderr, "StringStack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Free the string stack and its strings
void freeStringStack(StringStack *stack) {
    while (stack->top != -1) {
        free(stack->data[stack->top--]);
    }
    free(stack->data);
    free(stack);
}

// Helper function to ensure enoughs pace and concatenate the string safely.
char *appendString(char **dest, int *destCapacity, const char *src) {
    int needLength = strlen(*dest) + strlen(src) + 1;
    if (needLength >= *destCapacity) {
        // Increase the capacity,
        // double it until it can hold the new string.
        while (*destCapacity < needLength) {
            *destCapacity *= 2;
        }

        *dest = (char *)realloc(*dest, *destCapacity);
        if (!(*dest)) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    // Now we can safely concatenate the string.
    strcat(*dest, src);
    return *dest;
}

char *decodeString(char *s) {
    IntStack *intStack = createIntStack(INITIAL_CAPACITY);
    StringStack *stringStack = createStringStack(INITIAL_CAPACITY);

    // Allocate the mutable buffer for currentString (the length is dynamic,
    // even in C.)
    int currentCapacity = STRING_BUFFER_SIZE;
    char *currentString = (char *)malloc(currentCapacity);
    memset(currentString, 0, currentCapacity);
    if (!currentString) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int currentNumber = 0;
    int sLength = strlen(s);

    for (int index = 0; index < sLength; index++) {
        char currentCharacter = s[index];

        if (currentCharacter >= '0' && currentCharacter <= '9') {
            // If the current character is a digit, we need to parse the number.
            currentNumber = currentNumber * 10 + (currentCharacter - '0');
        } else if (currentCharacter == '[') {
            // Push the current number and string to the stacks.
            pushIntStack(intStack, currentNumber);
            pushStringStack(stringStack, currentString);

            // Reset currentString.
            memset(currentString, 0, currentCapacity);

            // Reset the current number.
            currentNumber = 0;
        } else if (currentCharacter == ']') {
            int repeatTimes = popIntStack(intStack);
            char *lastString = popStringStack(stringStack);

            // Build a new string by...
            // lastString + currentString * repeatTimes
            int newCapacity =
                strlen(lastString) + strlen(currentString) * repeatTimes + 1;
            char *temp = (char *)malloc(newCapacity);
            if (!temp) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            memset(temp, 0, newCapacity);
            strcat(temp, lastString); // First, just prepend the lastString.

            // Append the currentString to the new string for repeatTimes.
            for (int i = 0; i < repeatTimes; i++) {
                appendString(&temp, &newCapacity, currentString);
            }
            free(lastString);
            free(currentString);

            // Set the currentString to the new string.
            currentString = temp;
            currentCapacity = newCapacity;
        } else {
            // Append the regular character to the currentString.
            // However, we need to take care of the null-terminator.
            char temp[2] = {currentCharacter, '\0'};
            appendString(&currentString, &currentCapacity, temp);
        }
    }

    freeIntStack(intStack);
    freeStringStack(stringStack);

    return currentString;
}
