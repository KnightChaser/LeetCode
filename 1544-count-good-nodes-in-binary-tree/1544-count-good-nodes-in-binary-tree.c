/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

int countGoodNodes(struct TreeNode *root, int maximumInPath) {
    // If the current node is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    int count = 0;

    // If the current node is good(meaning it's value is greater than the
    // maximum value in the path), increment the count
    if (root->val >= maximumInPath) {
        count = 1;
        maximumInPath = root->val;
    }

    // Recursively call the function for the left and right children
    count += countGoodNodes(root->left, maximumInPath);
    count += countGoodNodes(root->right, maximumInPath);

    return count;
}

int goodNodes(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    return countGoodNodes(root, root->val);
}
