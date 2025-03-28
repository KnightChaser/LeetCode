/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

int minDepth(struct TreeNode *root) {
    // If the root is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    // If the root has only right child,
    // compute depth solely on the right child
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }

    // If the root has only left child
    // compute depth solely on the left child
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }

    // If both children are present, compute the depth,
    // and take the minimum of the two
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
}
