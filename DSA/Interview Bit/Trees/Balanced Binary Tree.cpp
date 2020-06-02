/**

https://www.interviewbit.com/problems/balanced-binary-tree/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getHeight(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    return 1 + max(getHeight(root->left),getHeight(root->right));
}
int Solution::isBalanced(TreeNode* root) 
{
    if(root == NULL)
        return 1;
    
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    
    if(abs(lh-rh) <= 1)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return 0;
}
