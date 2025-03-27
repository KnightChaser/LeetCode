/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int treeDepth(struct TreeNode* root) {
    if (root == NULL) {
        // It means we reach the leaf node
        return 0;
    }
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);

    // As we return to the parent node one by one,
    // We count up the depth of the tree one by one
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int maxDepth(struct TreeNode* root) {
    int depth = treeDepth(root);

    return depth;
}
