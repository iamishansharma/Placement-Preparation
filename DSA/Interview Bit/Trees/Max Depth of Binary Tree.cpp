/**

https://www.interviewbit.com/problems/max-depth-of-binary-tree/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::maxDepth(TreeNode* root) 
{
    if(root == NULL)
        return INT_MIN;
        
    if(root->left == NULL && root->right == NULL)
        return 1;
        
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
