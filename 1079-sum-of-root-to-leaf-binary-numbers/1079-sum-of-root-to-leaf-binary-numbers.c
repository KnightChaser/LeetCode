/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

int dfs(struct TreeNode *root, int sum) {
    // If the root is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    // Update the sum.
    // - Shift the number so far to the left by 1 bit
    // - Add the new bit to the right
    sum = (sum << 1) + root->val;

    // If the root is a leaf node, return the sum
    // because there is no more child nodes to visit
    if (root->left == NULL && root->right == NULL) {
        return sum;
    }
    // Return the sum of the left and right subtrees
    int leftSum = dfs(root->left, sum);
    int rightSum = dfs(root->right, sum);
    return leftSum + rightSum;
}

int sumRootToLeaf(struct TreeNode *root) {
    // If the root is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    return dfs(root, 0);
}
