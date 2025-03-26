#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Stack boilerplate
typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

void initStack(Stack *s, int size) {
    s->data = (int *)calloc(size, sizeof(int));
    s->size = 0;
    s->capacity = size;
}

bool isStackEmpty(Stack *s) { return s->size == 0; }

bool isStackFull(Stack *s) { return s->size == s->capacity; }

void stackPush(Stack *s, int val) {
    if (isStackFull(s)) {
        // Suppose we just don't allow stack to be full
        fprintf(stderr, "Stack is full\n");
        return;
    }
    s->data[s->size++] = val;
}

int stackPop(Stack *s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    int temp = s->data[s->size - 1];
    s->size--;
    s->data[s->size] = 0; // Invalidate the data
    return temp;
}

int stackPeek(Stack *s) {
    if (isStackEmpty(s)) {
        return -1;
    }
    return s->data[s->size - 1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
    Stack asteroidStack;
    initStack(&asteroidStack, asteroidsSize);

    for (int i = 0; i < asteroidsSize; i++) {
        int asteroid = asteroids[i];

        // Collision happens only when asteroid is moving left (negative),
        // and there is a right-moving asteroid in the stack
        if (asteroid > 0) {
            stackPush(&asteroidStack, asteroid);
        } else {
            // Process potential collision
            while (!isStackEmpty(&asteroidStack) &&
                   stackPeek(&asteroidStack) > 0 &&
                   abs(asteroid) > stackPeek(&asteroidStack)) {
                // The right-moving asteroid is destroyed
                stackPop(&asteroidStack);
            }

            // If there's a collision with equal size,
            // both asteroids are destroyed.
            if (!isStackEmpty(&asteroidStack) &&
                stackPeek(&asteroidStack) > 0 &&
                stackPeek(&asteroidStack) == abs(asteroid)) {
                // (destroyed)
                stackPop(&asteroidStack);
            } else {
                // If the stack is empty or the top is moving left,
                // push the current asteroid to the stack(top and asteroid are
                // moving in the same dairection)
                if (isStackEmpty(&asteroidStack) ||
                    stackPeek(&asteroidStack) < 0) {
                    stackPush(&asteroidStack, asteroid);
                }
            }
        }
    }

    // Prepare the answer array
    *returnSize = asteroidStack.size;
    int *result = (int *)malloc(sizeof(int) * asteroidStack.size);
    for (int i = 0; i < asteroidStack.size; i++) {
        result[i] = asteroidStack.data[i];
    }

    free(asteroidStack.data);
    return result;
}
