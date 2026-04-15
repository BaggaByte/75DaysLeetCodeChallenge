int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}