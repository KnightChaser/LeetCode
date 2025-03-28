/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Structure to store information about a node
typedef struct {
    int depth;
    struct TreeNode *parent;
} NodeInfo;

#include <stdbool.h>
#include <stdlib.h>

// Helper function that searches for the target node in the tree,
// and records its depth and parent in the provided NodeInfo structure.
void findNode(struct TreeNode *root, int target, int currentDepth,
              struct TreeNode *parent, NodeInfo *info) {
    // If the root is null, then immediately return NULL.
    if (root == NULL) {
        return;
    }

    // If the current node matches the target value
    if (root->val == target) {
        info->depth = currentDepth;
        info->parent = parent;
        return;
    }

    // If the target node is not found in the current node,
    // we have to search the left and right subtrees (further).
    findNode(root->left, target, currentDepth + 1, root, info);
    findNode(root->right, target, currentDepth + 1, root, info);
}

bool isCousins(struct TreeNode *root, int x, int y) {
    // If the root node is NULL
    if (root == NULL) {
        return false;
    }

    // Initialize the Node information structure
    NodeInfo xInfo = {
        .depth = -1,
        .parent = NULL,
    };
    NodeInfo yInfo = {
        .depth = -1,
        .parent = NULL,
    };

    findNode(root, x, 0, NULL, &xInfo);
    findNode(root, y, 0, NULL, &yInfo);

    // To be cousins, the nodes must be at the same depth
    // and have different parents
    if (xInfo.depth == yInfo.depth && xInfo.parent != yInfo.parent) {
        return true;
    } else {
        return false;
    }
}
