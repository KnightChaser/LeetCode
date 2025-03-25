#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Integer queue
typedef struct {
    int *data;
    int frontIndex;
    int rearIndex;
    int capacity;
} Queue;

// Check if the given queue is empty
bool isEmpty(Queue *queue) { return queue->frontIndex == queue->rearIndex; }

// Initialize queue
void initQueue(Queue *queue, int capacity) {
    queue->data = (int *)calloc(sizeof(int) * capacity, sizeof(int));
    queue->frontIndex = 0;
    queue->rearIndex = 0;
    queue->capacity = capacity;
}

// Insert an element intoe the queue
void enqueue(Queue *queue, int value) {
    if ((queue->rearIndex + 1) % queue->capacity == queue->frontIndex) {
        fprintf(stderr, "Queue is full\n");
        return;
    }

    queue->data[queue->rearIndex] = value;
    queue->rearIndex = (queue->rearIndex + 1) % queue->capacity;
}

// Extract an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }

    // Return the front element which is at the frontIndex
    int value = queue->data[queue->frontIndex];
    queue->frontIndex = (queue->frontIndex + 1) % queue->capacity;
    return value;
}

char *predictPartyVictory(char *senate) {
    int senateLen = strlen(senate);
    Queue senateR, senateD;
    initQueue(&senateR, senateLen);
    initQueue(&senateD, senateLen);

    if (senateLen == 1) {
        // Edge case: If there is only one senator, he/she wins
        if (senate[0] == 'R') {
            return "Radiant";
        } else {
            return "Dire";
        }
    }

    // Fill queues with the senators' indices
    for (int i = 0; i < senateLen; i++) {
        if (senate[i] == 'R') {
            enqueue(&senateR, i);
        } else {
            enqueue(&senateD, i);
        }
    }

    // Simulate the round process
    while (!isEmpty(&senateR) && !isEmpty(&senateD)) {
        int rIndex = dequeue(&senateR);
        int dIndex = dequeue(&senateD);

        if (rIndex < dIndex) {
            enqueue(&senateR, rIndex + senateLen);
        } else {
            enqueue(&senateD, dIndex + senateLen);
        }
    }

    free(senateR.data);
    free(senateD.data);

    // If the Radiant queue is empty, the Dire wins. And, vice versa.
    return isEmpty(&senateR) ? "Dire" : "Radiant";
}
