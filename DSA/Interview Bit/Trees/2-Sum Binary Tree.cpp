/**

https://www.interviewbit.com/problems/2sum-binary-tree/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void GetData(TreeNode* A, int B, map<int,bool> &mp)
{
    if(A==NULL) 
        return;
        
    GetData(A->left,B,mp);
    
    if(mp.find(B-(A->val)) == mp.end())
        mp[A->val]=false;
    else 
        mp[A->val]=true;
        
    GetData(A->right,B,mp);
}
int Solution::t2Sum(TreeNode* A, int B) 
{
    map<int,bool> mp;
    
    GetData(A,B,mp);
    
    for(auto i : mp)
        if(i.second == true)
            return 1;
            
    return 0;
}