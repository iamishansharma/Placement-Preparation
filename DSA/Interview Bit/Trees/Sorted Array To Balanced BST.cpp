/**

https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* sortedBST(const vector<int> &A,int s,int e)
{
    if(s>e) 
        return NULL;
        
    int mid = (s+e)/2;
    
    TreeNode* r = new TreeNode(A[mid]);
    r->left = sortedBST(A,s,mid-1);
    r->right = sortedBST(A,mid+1,e);
    
    return r;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    int s=0, e=A.size()-1;
    return sortedBST(A,s,e);
}
