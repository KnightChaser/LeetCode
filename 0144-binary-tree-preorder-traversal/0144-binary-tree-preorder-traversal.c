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


#include <stdio.h>
#include <stdlib.h>

// ----- Dynamic list boilerplate as a form of linked list -----
// (At this moment, we only need the insertion operation)
typedef struct DynamicListNode {
    int value;
    struct DynamicListNode *next;
} DynamicListNode;

typedef struct DynamicList {
    DynamicListNode *head;
    DynamicListNode *tail;
    int size;
} DynamicList;

void initializeList(DynamicList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Insert a new node at the end of the list
void insert(DynamicList *list, int value) {
    DynamicListNode *newNode =
        (DynamicListNode *)malloc(sizeof(DynamicListNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (list->size == 0) {
        // If the list is empty, the new node is both the head and the tail
        list->head = newNode;
        list->tail = newNode;
    } else {
        // If the list is not empty, the new node is the new tail
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

// Free the memory allocated for the list
void freeList(DynamicList *list) {
    DynamicListNode *current = list->head;
    while (current) {
        DynamicListNode *next = current->next;
        free(current);
        current = next;
    }
}

void preOrder(struct TreeNode *root, DynamicList *list) {
    // If the root is NULL, return
    if (!root) {
        return;
    }

    insert(list, root->val);
    preOrder(root->left, list);
    preOrder(root->right, list);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    // If there is no root, return an empty list
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    DynamicList list;
    initializeList(&list);
    preOrder(root, &list);

    // Form the result array
    int *result = (int *)malloc(list.size * sizeof(int));
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        freeList(&list);
        *returnSize = 0;
        return NULL;
    }

    *returnSize = list.size;
    DynamicListNode *current = list.head;
    for (int i = 0; i < list.size; i++) {
        result[i] = current->value;
        current = current->next;
    }

    freeList(&list);

    return result;
}
