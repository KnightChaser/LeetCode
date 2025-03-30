/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdbool.h>
#define MAX_ELEMENTS 10000

void inOrder(struct TreeNode *root, int *elements, int *index) {
    // If the root is NULL, return
    if (root == NULL) {
        return;
    }

    inOrder(root->left, elements, index);
    elements[*index] = root->val;
    (*index)++;
    inOrder(root->right, elements, index);
}

bool findTarget(struct TreeNode* root, int k) {
    // If there is nothing to search, return false
    if (root == NULL) {
        return false;
    }

    int elements[MAX_ELEMENTS];

    int index = 0;
    inOrder(root, elements, &index);

    // Now, check if there are two elements
    // in the array that sum up to k
    // (The array elements[] is ascendingly sorted)
    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (elements[i] + elements[j] == k) {
                return true;
            }
        }
    }
    return false;
}
