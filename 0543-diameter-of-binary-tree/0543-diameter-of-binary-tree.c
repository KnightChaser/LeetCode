/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

int getDiameter(struct TreeNode *root, int *diameter) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    // Recursively get the height of the left and right subtrees
    int leftHeight = getDiameter(root->left, diameter);
    int rightHeight = getDiameter(root->right, diameter);

    // The diameter of the tree is :
    // height of left subtree + height of right subtree + 1
    if (leftHeight + rightHeight > *diameter) {
        *diameter = leftHeight + rightHeight;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int diameterOfBinaryTree(struct TreeNode *root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    int diameter = 0;
    getDiameter(root, &diameter);

    return diameter;
}
