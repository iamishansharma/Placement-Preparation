/**

https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Ksmallest(TreeNode* A,int &p,int &e)
{
    if(A==NULL)
        return;
        
    Ksmallest(A->left,p,e);
    
    p--;
    if(p==0)
    {
        e = A->val;
        return;
    }
    
    Ksmallest(A->right,p,e);
}
int Solution::kthsmallest(TreeNode* A, int B)
{
    int e = 0;
    Ksmallest(A,B,e);
    return e;
}
