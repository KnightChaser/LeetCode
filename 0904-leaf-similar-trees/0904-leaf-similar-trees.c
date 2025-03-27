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
#define MAX_TREE_NODES 100

void dfsTreeTraversal(struct TreeNode *root, int *leaf, int *index) {
    // If the root is NULL, then return
    if (root == NULL) {
        return;
    }

    dfsTreeTraversal(root->left, leaf, index);

    // If the root is a leaf node, then add the value to the leaf array
    if (root->left == NULL && root->right == NULL) {
        leaf[(*index)] = root->val;
        (*index)++;
    }

    dfsTreeTraversal(root->right, leaf, index);
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
    int leaf1[MAX_TREE_NODES] = {0};
    int leaf2[MAX_TREE_NODES] = {0};
    int index1 = 0, index2 = 0;

    // Now, conduct the DFS to get the leaf sequence of the two trees
    dfsTreeTraversal(root1, leaf1, &index1);
    dfsTreeTraversal(root2, leaf2, &index2);

    // Check if the two leaf sequences are the same
    for (int i = 0; i < MAX_TREE_NODES; i++) {
        if (leaf1[i] != leaf2[i]) {
            return false;
        }
    }

    return true;
}
