/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdio.h>
#define MAX_ARRAY_SIZE 10000

// Conduct in-order tree traversal
// During the traversal, store the values in the array with the given index
void inOrderTreeTraversal(struct TreeNode *root, int *values, int *index) {
    // If the tree is empty, return immediately
    if (root == NULL) {
        return;
    }

    inOrderTreeTraversal(root->left, values, index);

    // Store the current node's value
    values[*index] = root->val;
    (*index)++;

    inOrderTreeTraversal(root->right, values, index);
}

int getMinimumDifference(struct TreeNode *root) {
    // If the tree is empty, return 0 (nothing to proceed)
    if (root == NULL) {
        return 0;
    }

    // Note that
    // - the number of nodes in the tree is in the range [2, 10^4]
    // - 0 <= Node.val <= 10^5
    int values[MAX_ARRAY_SIZE];
    int index = 0;

    inOrderTreeTraversal(root, values, &index);

    // Inorder traversal sorts the values in ascending order
    // The minimum difference is the minimum difference
    // between two adjacent values
    int minDiff = INT_MAX;
    for (int i = 0; i < index - 1; i++) {
        int diff = values[i + 1] - values[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}
