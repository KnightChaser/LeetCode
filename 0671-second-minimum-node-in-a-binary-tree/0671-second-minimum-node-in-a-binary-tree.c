/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>
#include <stdio.h>

void dfs(struct TreeNode *root, int min, int *secondMin) {
    // Nothing to do
    if (root == NULL) {
        return;
    }

    if (root->val > min) {
        // Update secondMin if this is the first candidate or a batter candidate
        if (*secondMin == -1 || root->val < *secondMin) {
            *secondMin = root->val;
        }
    } else if (root->val == min) {
        // Only continue to search if the value is the same as the min
        // If a node's value is already greater than the minimum, we don't need
        // to go deeper in that branch for another candidateâany descendant
        // would be equal to or larger than that node's value.
        // => root.val = min(root.left.val, root.right.val)
        dfs(root->left, min, secondMin);
        dfs(root->right, min, secondMin);
    }
}

int findSecondMinimumValue(struct TreeNode *root) {
    if (root == NULL) {
        return -1;
    }

    // 1 <= Node.val <= 2^31 - 1
    int secondMin = -1;
    dfs(root, root->val, &secondMin);
    return secondMin;
}
