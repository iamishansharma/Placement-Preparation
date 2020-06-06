/**

https://www.interviewbit.com/problems/path-sum/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void rec(TreeNode *root, int sum, int currsum, int &flag)
{
    if(root == NULL)
        return;
        
    currsum += root->val;
    if(root->left == NULL && root->right == NULL)
    {
        if(currsum == sum)
            flag = 1;
    }
    
    rec(root->left, sum, currsum, flag);
    rec(root->right, sum, currsum, flag);
}

int Solution::hasPathSum(TreeNode* root, int sum) 
{
    if(root == NULL)
        return 0;
        
    int flag = 0;
    
    rec(root, sum, 0, flag);
    
    return flag;
}
