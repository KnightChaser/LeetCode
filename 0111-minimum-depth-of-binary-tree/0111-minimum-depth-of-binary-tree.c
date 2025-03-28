/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

int calculateMinDepth(struct TreeNode *root, int depth) {
    // Debug print
    printf("Node: %d, Depth: %d\n", root->val, depth);

    // If the left child is NULL, then the depth is the depth of the right child
    if (root->left == NULL && root->right == NULL) {
        return depth;
    }

    // If left child is NULL, then the depth is the depth of the right child
    if (root->left == NULL) {
        return calculateMinDepth(root->right, depth + 1);
    }

    // If right child is NULL, then the depth is the depth of the left child
    if (root->right == NULL) {
        return calculateMinDepth(root->left, depth + 1);
    }

    // If both children are not NULL, then the depth is the minimum of the left
    // and right children
    int leftDepth = calculateMinDepth(root->left, depth + 1);
    int rightDepth = calculateMinDepth(root->right, depth + 1);

    return leftDepth < rightDepth ? leftDepth : rightDepth;
}

int minDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    return calculateMinDepth(root, 1);
}
