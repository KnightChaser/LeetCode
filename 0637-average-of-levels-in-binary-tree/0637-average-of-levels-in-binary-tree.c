/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ----- Queue boilerplate -----
typedef struct QueueNode {
    struct TreeNode *data;
    struct QueueNode *next;
    int level; // level of the node in the tree
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isQueueEmpty(Queue *q) { return q->front == NULL; }

void enqueue(Queue *q, struct TreeNode *data, int level) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->level = level;
    newNode->next = NULL;

    if (q->rear == NULL) {
        // If queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else {
        // If queue is not empty
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue *q, struct TreeNode **data, int *level) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        return;
    }

    // Fetch the data from the front of the queue
    QueueNode *temp = q->front;
    *data = temp->data;
    *level = temp->level;

    // Now remove the node from the queue
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

double *averageOfLevels(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (!root) {
        // No elements in the tree
        return NULL;
    }

    // Weâll store the sums and counts in dynamic arrays,
    // which we can extend if we encounter deeper levels than expected.
    int capacity = 8;
    long long *levelSumArray = (long long *)calloc(capacity, sizeof(long long));
    int *levelCountArray = (int *)calloc(capacity, sizeof(int));
    if (!levelSumArray || !levelCountArray) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // BFS queue
    Queue q;
    initializeQueue(&q);
    enqueue(&q, root, 0); // root is at level 0

    int maxLevel = 0; // Track the deepest level weâve seen so far

    // Conduct the level order traversal
    while (!isQueueEmpty(&q)) {
        struct TreeNode *currentNode;
        int level;
        dequeue(&q, &currentNode, &level);

        // If the level is beyond the current capacity of the arrays,
        // we need to extend the arrays
        if (level >= capacity) {
            // Double the capacity until it is enough
            while (level >= capacity) {
                capacity *= 2;
            }
            levelSumArray = (long long *)realloc(levelSumArray,
                                                 capacity * sizeof(long long));
            levelCountArray =
                (int *)realloc(levelCountArray, capacity * sizeof(int));
            if (!levelSumArray || !levelCountArray) {
                fprintf(stderr, "Memory allocation failed\n");
                return NULL;
            }

            // Initialize the new elements (after half the capacity)
            for (int i = capacity / 2; i < capacity; i++) {
                levelSumArray[i] = 0;
                levelCountArray[i] = 0;
            }
        }

        // Update sums and counts
        levelSumArray[level] += currentNode->val;
        levelCountArray[level]++;

        // Update maxLevel if needed
        if (level > maxLevel) {
            maxLevel = level;
        }

        // Enqueue the children (+1 depth)
        if (currentNode->left != NULL) {
            enqueue(&q, currentNode->left, level + 1);
        }
        if (currentNode->right != NULL) {
            enqueue(&q, currentNode->right, level + 1);
        }
    }

    // Now build the result array
    *returnSize = maxLevel + 1;
    double *result = (double *)calloc(*returnSize, sizeof(double));
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Calculate the averages
    for (int i = 0; i <= maxLevel; i++) {
        result[i] = (double)levelSumArray[i] / levelCountArray[i];
    }

    free(levelSumArray);
    free(levelCountArray);

    return result;
}
