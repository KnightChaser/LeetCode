#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// A simple "growable" array of struct TreeNode
struct TreeList {
    struct TreeNode **trees;
    int size;
};

static struct TreeList build(int k, struct TreeList *memo, bool *visited) {
    // If it's already computed, return the memoized result
    if (visited[k]) {
        return memo[k];
    }

    struct TreeList result = {.trees = NULL, .size = 0};

    if (k % 2 == 0) {
        // No full binary tree with an even number of nodes
    } else if (k == 1) {
        // Base case: a single node
        struct TreeNode *leafNode = malloc(sizeof(struct TreeNode));
        if (!leafNode) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        leafNode->val = 0;
        leafNode->left = NULL;
        leafNode->right = NULL;

        // The result is a single node
        result.trees = malloc(sizeof(struct TreeNode *));
        if (!result.trees) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        result.trees[0] = leafNode;
        result.size = 1;
    } else {
        // Recursive case: try every odd split of remaining nodes into left and
        // right subtrees
        for (int L = 1; L < k; L += 2) {
            int R = k - 1 - L;
            struct TreeList leftList = build(L, memo, visited);
            struct TreeList rightList = build(R, memo, visited);

            for (int i = 0; i < leftList.size; i++) {
                for (int j = 0; j < rightList.size; j++) {
                    struct TreeNode *root = malloc(sizeof(struct TreeNode));
                    if (!root) {
                        perror("malloc");
                        exit(EXIT_FAILURE);
                    }

                    // Set the root node
                    root->val = 0;
                    root->left = leftList.trees[i];
                    root->right = rightList.trees[j];

                    // Append the new tree to the result
                    // Note that the size of the result is incremented by one
                    result.trees =
                        realloc(result.trees,
                                (result.size + 1) * sizeof(struct TreeNode *));
                    result.trees[result.size] = root;
                    result.size++;
                }
            }
        }
    }

    visited[k] = true; // Note that we mark this as visited
    memo[k] = result;  // We store the result in the memoization array
    return result;
}

struct TreeNode **allPossibleFBT(int n, int *returnSize) {
    // Allocate the memo table of size (n+1) first >_<
    struct TreeList *memo = calloc(n + 1, sizeof(struct TreeList));
    bool *visited = calloc(n + 1, sizeof(bool));
    if (!memo || !visited) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memset(visited, false, (n + 1) * sizeof(bool));

    struct TreeList answer = build(n, memo, visited);
    *returnSize = answer.size;

    free(memo);    // Free the memoization table (not used anymore)
    free(visited); // Free the visited array (not used anymore)

    return answer.trees;
}
