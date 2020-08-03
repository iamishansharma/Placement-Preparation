/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void change(TreeNode *root, TreeNode *&pre)
{
    if(root == NULL)
        return;
    
    change(root->right, pre);
    change(root->left, pre);
    
    root->right = pre;
    root->left = NULL;
    pre = root;
}
TreeNode* Solution::flatten(TreeNode* root) 
{
    TreeNode *pre = NULL;
    change(root, pre);
    return root;
}
