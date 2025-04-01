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

// Note that the given binary tree guarantees that
// all the nodes are present in the tree

int countNodes(struct TreeNode *root) {
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    // Check if the tree is a complete binary tree
    int leftHeight = 0;
    struct TreeNode *leftNode = root;
    while (leftNode != NULL) {
        leftHeight++;
        leftNode = leftNode->left;
    }

    int rightHeight = 0;
    struct TreeNode *rightNode = root;
    while (rightNode != NULL) {
        rightHeight++;
        rightNode = rightNode->right;
    }

    if (leftHeight == rightHeight) {
        // The tree is a complete binary tree
        return (1 << leftHeight) - 1; // 2^h - 1
    }

    // If not a complete binary tree, count nodes recursively.
    // At some moment, the split trees will be complete binary trees.
    return 1 + countNodes(root->left) + countNodes(root->right);
}
