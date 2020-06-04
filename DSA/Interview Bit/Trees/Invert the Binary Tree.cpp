// https://www.interviewbit.com/problems/invert-the-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inv(TreeNode *root)
{
    if(root == NULL)
        return;
        
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    inv(root->left);
    inv(root->right);
}

TreeNode* Solution::invertTree(TreeNode* root) 
{
    if(root == NULL)
        return root;
        
    inv(root);
    
    return root;
}
