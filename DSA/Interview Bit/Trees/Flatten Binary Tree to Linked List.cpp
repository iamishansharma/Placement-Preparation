/**

https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *pre;

void change(TreeNode *root)
{
    if(!root)
        return;
    
    change(root->right);
    change(root->left);
    
    root->right = pre;
    root->left = NULL;
    pre = root;
}
TreeNode* Solution::flatten(TreeNode* root) 
{
    pre=NULL;
    change(root);
    return root;
}
