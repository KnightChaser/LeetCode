/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// We use the bottom-up approach to solve this problem
int dfsBottomUp(struct TreeNode *root) {
    // If this is the left node, we consider the depth of the right node
    if (root == NULL) {
        return 0;
    }

    // Find the depth of the left node of the current node
    int leftDepth = dfsBottomUp(root->left);
    int rightDepth = dfsBottomUp(root->right);

    // If the left node is not balanced, return -1
    if (abs(leftDepth - rightDepth) > 1 || leftDepth == -1 ||
        rightDepth == -1) {
        // If abs(leftDepth - rightDepth) > 1, this will immediately return -1,
        // and this "signal" will be propagated up to the root node
        return -1;
    }

    return fmax(leftDepth, rightDepth) + 1;
}

bool isBalanced(struct TreeNode *root) {
    if (root == NULL) {
        return true;
    }

    if (dfsBottomUp(root) == -1) {
        return false;
    } else {
        return true;
    }
}
