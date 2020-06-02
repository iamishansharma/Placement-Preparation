/**

https://www.interviewbit.com/problems/least-common-ancestor/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool search(TreeNode* root,int a)
{
    if(root == NULL)
        return false;
        
    if(root->val == a)
        return true;
        
    return (search(root->left,a) || search(root->right,a));
}
int Solution::lca(TreeNode* a, int b, int c) 
{
    if(!(search(a,b) && search(a,c)))
        return -1;
    
    if(search(a->left,b) && search(a->left,c))
        return lca(a->left,b,c);
        
    if(search(a->right,b) && search(a->right,c))
        return lca(a->right,b,c);
        
    return a->val;
}
