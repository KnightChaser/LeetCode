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
    int currentDiameter = leftHeight + rightHeight + 1;
    if (currentDiameter > *diameter) {
        *diameter = currentDiameter;
    }

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int diameterOfBinaryTree(struct TreeNode *root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    int diameter = 0;
    getDiameter(root, &diameter);

    // Return the diameter of the tree
    // -1 because the diameter is the number of edges between the two nodes,
    // so there is one less node than the number of edges actually
    return diameter - 1;
}
