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

bool areSameTrees(struct TreeNode *p, struct TreeNode *q) {
    // If both trees are empty, they are the same
    if (p == NULL && q == NULL) {
        return true;
    }

    // If one of the trees is empty, they are not the same
    if (p == NULL || q == NULL) {
        return false;
    }

    // If the values of the nodes are different, they are not the same
    if (p->val != q->val) {
        return false;
    }

    // Now, we have to check the left and right subtrees further
    return areSameTrees(p->left, q->left) && areSameTrees(p->right, q->right);
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    // Edge cases
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }

    return areSameTrees(p->left, q->left) && areSameTrees(p->right, q->right);
}
