/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ----- Queue boilerplate -----
typedef struct QueueNode {
    struct TreeNode *node;
    int sumSoFar; // Keep track of the sum so far
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
} Queue;

void initializeQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

bool isQueueEmpty(Queue *queue) { return queue->head == NULL; }

void enqueue(Queue *queue, struct TreeNode *node, int sumSoFar) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return;
    }
    newNode->node = node;
    newNode->sumSoFar = sumSoFar;
    newNode->next = NULL;

    if (queue->head == NULL) {
        // If the queue is empty, set the head and tail to the new node
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        // If the queue is not empty, add the new node to the end of the queue
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void dequeue(Queue *queue, struct TreeNode **node, int *sumSoFar) {
    if (isQueueEmpty(queue)) {
        *node = NULL;
        *sumSoFar = 0;
        fprintf(stderr, "Cannot dequeue from an empty queue\n");
        return;
    }

    // Fetch the node at the head of the queue
    QueueNode *temp = queue->head;
    *node = temp->node;
    *sumSoFar = temp->sumSoFar;

    // The head of the queue is now the next node
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    // The node is no longer needed
    free(temp);
}

bool hasPathSum(struct TreeNode *root, int targetSum) {
    // There is nothing left in the tree
    if (root == NULL) {
        return false;
    }

    Queue queue;
    initializeQueue(&queue);

    // Start the BFS(Breadth First Search) from the root node
    // and the sum so far is the value of the root node
    enqueue(&queue, root, root->val);

    while (!isQueueEmpty(&queue)) {
        struct TreeNode *currentNode = NULL;
        int currentSum = 0;
        dequeue(&queue, &currentNode, &currentSum);

        // If there is a leaf node(having no children),
        // check if the sum so far is equal to the target sum
        if (currentNode->left == NULL && currentNode->right == NULL) {
            if (currentSum == targetSum) {
                return true;
            }
        }

        // Otherwise, add the children of the current node to the queue
        if (currentNode->left != NULL) {
            enqueue(&queue, currentNode->left,
                    currentSum + currentNode->left->val);
        }

        if (currentNode->right != NULL) {
            enqueue(&queue, currentNode->right,
                    currentSum + currentNode->right->val);
        }
    }

    return false;
}
