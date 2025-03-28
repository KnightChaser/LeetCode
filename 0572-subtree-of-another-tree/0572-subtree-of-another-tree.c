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

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot) {
    // Edge cases
    if (root == NULL) {
        return false;
    }

    // If the subRoot is null, then it is a subtree of anything
    if (subRoot == NULL) {
        return true;
    }

    // At some point, we will find the subtreea inside the root tree
    // if the subtree exists
    if (areSameTrees(root, subRoot)) {
        return true;
    }

    // Not found yet, so we have to check the left and right subtrees
    // (Goind deeper in the tree)
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
