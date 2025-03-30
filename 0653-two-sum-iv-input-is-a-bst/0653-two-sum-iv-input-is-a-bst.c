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
    int startIndex = 0;
    int endIndex = index - 1;
    while (startIndex < endIndex) {
        int sum = elements[startIndex] + elements[endIndex];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            // If the current sum is less than the target,
            // We move startIndex to the right to add bigger numbers
            startIndex++;
        } else {
            // If the current sum is bigger than the target,
            // We move endIndex to the left to add smaller numbers
            endIndex--;
        }
    }

    return false;
}
