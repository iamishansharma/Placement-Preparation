/**

https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void sumleaf(TreeNode *root, long long sum, long long &ans)
{
    if(root==NULL)
        return;
        
    sum = (sum*10 + root->val) % 1003;
    
    if(root->left==NULL && root->right==NULL)
    {
        ans = ans+sum;
        return;
    }
    
    sumleaf(root->left,sum,ans);
    sumleaf(root->right,sum,ans);
}
int Solution::sumNumbers(TreeNode* root) 
{
    long long sum=0;
    long long  ans=0;
    
    sumleaf(root,sum,ans);
    
    return (int)ans%1003; 
}
