#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 50021 // A prime number for a decent hash table size

// ----- Hashmap(dictionary) boilerplate code -----
typedef struct HashNode {
    int64_t key;           // Key (prefix sum), now using 64-bit
    int count;             // Value (frequency of the prefix sum)
    struct HashNode *next; // Next node in the linked list
} HashNode;

unsigned int hash(int64_t key) { return ((unsigned int)key) % TABLE_SIZE; }

void hashmapUpsert(HashNode **table, int64_t key, int delta) {
    unsigned int index = hash(key);
    HashNode *node = table[index];

    while (node) {
        if (node->key == key) {
            node->count += delta;
            return;
        }
        node = node->next;
    }

    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->key = key;
    newNode->count = delta;
    newNode->next = table[index];
    table[index] = newNode;
}

int hashmapGet(HashNode **table, int64_t key, int defaultReturn) {
    unsigned int index = hash(key);
    HashNode *node = table[index];

    while (node != NULL) {
        if (node->key == key) {
            return node->count;
        }
        node = node->next;
    }

    return (defaultReturn != 0) ? defaultReturn : 0;
}

void freeHashmap(HashNode **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *node = table[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode *root, int64_t currentSum, int targetSum,
        HashNode **table) {
    if (!root)
        return 0;

    // Calculate the new sum for the current node
    currentSum += root->val;

    // How many paths from the root to the current node have the target sum
    int count = hashmapGet(table, currentSum - targetSum, 0);

    // Now, increment the count of the current prefix sum.
    // From now on, we will search for the target sum from the current node
    hashmapUpsert(table, currentSum, 1);

    // Continue the search in the left and right subtrees
    count += dfs(root->left, currentSum, targetSum, table);
    count += dfs(root->right, currentSum, targetSum, table);

    // Backtrack: decrement the frequency of the current prefix sum
    // so it won't affect other paths
    // Note that we only store the prefix sum of the current path at any time
    // (Consider path can start from any node, not just the root)
    hashmapUpsert(table, currentSum, -1);

    return count;
}

int pathSum(struct TreeNode *root, int targetSum) {
    HashNode **table = (HashNode **)calloc(TABLE_SIZE, sizeof(HashNode *));
    if (!table) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with prefix sum of 0 occurring once.
    hashmapUpsert(table, 0, 1);

    int result = dfs(root, 0, targetSum, table);
    freeHashmap(table);
    return result;
}
