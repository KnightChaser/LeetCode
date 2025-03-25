#include <stdlib.h>

#define MAX_SIZE 10005

// Queue structure
typedef struct {
    int *data; // Data array
    int front; // Front pointer
    int rear;  // Rear pointer
    int size;  // THe size of the queue
} RecentCounter;

// Create a queue
RecentCounter *recentCounterCreate() {
    RecentCounter *queue = (RecentCounter *)malloc(sizeof(RecentCounter));
    queue->data = (int *)calloc(MAX_SIZE, sizeof(int));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return queue;
}

// Enqueue
int recentCounterPing(RecentCounter *obj, int t) {
    // Enqueue the new ping object
    obj->data[obj->rear] = t;
    obj->rear = (obj->rear + 1) % MAX_SIZE;

    // Dequeue the old ping object (criterion: 3,000 ms or older)
    while (obj->data[obj->front] < t - 3000) {
        obj->front = (obj->front + 1) % MAX_SIZE;
    }

    // Return the size of the "recent" ping objects
    return obj->rear - obj->front;
}

// Free the queue
void recentCounterFree(RecentCounter *obj) {
    free(obj->data); // queue's internal data array
    free(obj);       // queue itself
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
