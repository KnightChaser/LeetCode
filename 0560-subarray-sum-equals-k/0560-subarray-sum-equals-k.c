#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 50021 // A prime number for a decent hash table size

// ----- Hashmap(dictionary) boilerplate code -----
// Hash table node structure
typedef struct HashNode {
    int key;               // Key (prefix sum)
    int count;             // Value (frequency of the prefix sum)
    struct HashNode *next; // Next node in the linked list
} HashNode;

// Calculate the hash value of a key
unsigned int hash(int key) { return ((unsigned int)key) % TABLE_SIZE; }

// Insert or update a key-value pair in the hash table
// (Increase the count of key as many times as delta)
void hashmapUpsert(HashNode **table, int key, int delta) {
    unsigned int index = hash(key);
    HashNode *node = table[index];

    // Search for the key in the chain
    while (node) {
        if (node->key == key) {
            node->count += delta;
            return;
        }
        node = node->next;
    }

    // If the key is not found, create a new node
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

// Retrieve the count for a given key, return 0 if the key is not found
int hashmapGet(HashNode **table, int key, int defaultReturn) {
    unsigned int index = hash(key);
    HashNode *node = table[index];

    // Search for the key in the chain
    while (node != NULL) {
        if (node->key == key) {
            return node->count;
        }
        node = node->next;
    }

    // Customize the default return value
    if (defaultReturn != 0) {
        return defaultReturn;
    } else {
        return 0;
    }
}

// Free the hash table
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

int subarraySum(int *nums, int numsSize, int k) {
    int count = 0;
    int currentSum = 0;

    // Initialize the hash table(an array of pointers to HashNode)
    HashNode **table = (HashNode **)calloc(TABLE_SIZE, sizeof(HashNode *));
    if (!table) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Base case: an empty subarray with sum 0
    // At least sum=0 occurs at the very beginning
    hashmapUpsert(table, 0, 1);

    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];

        // Check if there's a prefix sum such that currentSum - prefixSum = k
        count += hashmapGet(table, currentSum - k, 0);

        // Update the frequency of the current prefix sum
        hashmapUpsert(table, currentSum, 1);
    }

    freeHashmap(table);

    return count;
}
