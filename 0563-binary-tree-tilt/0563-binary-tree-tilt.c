/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

int dfsTilt(struct TreeNode *root, int *tiltSum) {
    // If the root is NULL, return 0.
    // It makes the tilt of the leaf node zero.
    if (root == NULL) {
        return 0;
    }

    int leftSum = dfsTilt(root->left, tiltSum);
    int rightSum = dfsTilt(root->right, tiltSum);
    *tiltSum += abs(leftSum - rightSum);

    return leftSum + rightSum + root->val;
}

int findTilt(struct TreeNode *root) {
    // If the root is NULL, return 0
    if (root == NULL) {
        return 0;
    }

    int tiltSum = 0;
    dfsTilt(root, &tiltSum);

    return tiltSum;
}
