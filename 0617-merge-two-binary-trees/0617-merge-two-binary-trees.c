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

struct TreeNode *sumTree(struct TreeNode *root1, struct TreeNode *root2) {
    if (root1 != NULL && root2 != NULL) {
        struct TreeNode *newNode =
            (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
        newNode->val = root1->val + root2->val;
        newNode->left = sumTree(root1->left, root2->left);
        newNode->right = sumTree(root1->right, root2->right);

        return newNode;
    } else if (root1 != NULL && root2 == NULL) {
        // Only root1 exists
        return root1;
    } else if (root1 == NULL && root2 != NULL) {
        // Only root2 exists
        return root2;
    } else {
        // Both are NULL
        return NULL;
    }
}

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2) {
    // Edge cases
    if (root1 == NULL) {
        return root2;
    }

    if (root2 == NULL) {
        return root1;
    }

    struct TreeNode *newNode = sumTree(root1, root2);

    return newNode;
}
