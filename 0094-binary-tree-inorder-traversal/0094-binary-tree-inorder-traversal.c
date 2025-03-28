/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

// Conduct the inorder traversal
void inorder(struct TreeNode *root, int *returnSize, int *result) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    inorder(root->left, returnSize, result);
    result[*returnSize] = root->val;
    (*returnSize)++;
    inorder(root->right, returnSize, result);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    struct TreeNode *current = root;
    int *result = (int *)calloc(100, sizeof(int));
    *returnSize = 0;

    inorder(current, returnSize, result);

    return result;
}
