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

bool isMirror(struct TreeNode *left, struct TreeNode *right) {
    // If both are NULL, then they are mirrored.
    if (left == NULL && right == NULL) {
        return true;
    }

    // If one of them is NULL, then they are not mirrored.
    if (left == NULL || right == NULL) {
        return false;
    }

    // The values of the nodes must be equal.
    if (left->val != right->val) {
        return false;
    }

    // Now, we must ensure that the following to ensure mirrority:
    // - left.left == right.right
    // - left.right == right.left
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root) {
    // NULL is just considered symmetric.
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}
