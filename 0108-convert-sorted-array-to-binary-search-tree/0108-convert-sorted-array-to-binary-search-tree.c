/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode *bsf(int *nums, int numsSize) {
    // Calculate the middle index
    int middleIndex = numsSize / 2;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[middleIndex];
    root->left = NULL;
    root->right = NULL;

    // If the left side is not empty, recursively call the function
    if (middleIndex > 0) {
        root->left = bsf(nums, middleIndex);
    }

    // If the right side is not empty, recursively call the function
    if (middleIndex + 1 < numsSize) {
        root->right = bsf(nums + middleIndex + 1, numsSize - middleIndex - 1);
    }

    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    // If the array is empty, return NULL
    if (numsSize == 0) {
        return NULL;
    }

    return bsf(nums, numsSize);
}
