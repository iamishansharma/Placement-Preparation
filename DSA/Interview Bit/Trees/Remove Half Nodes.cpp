/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root) 
{
    if(root == NULL)
        return root;
    
    root->left = solve(root->left);
    root->right = solve(root->right);
    
    if(root->left == NULL && root->right == NULL)
        return root;
    if(root->left == NULL)
        return root->right;
    if(root->right == NULL)
        return root->left;
    return root;
}
