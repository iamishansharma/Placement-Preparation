/**

https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *build(vector<int> &a, vector<int> &b,unordered_map<int,int> &m, int &pre, int start, int end)
{
    if(start>end) 
        return NULL;
        
    int curr = a[pre++];
    
    TreeNode *root = new TreeNode(curr);
    root->left = build(a,b,m,pre,start,m[curr]-1);
    root->right = build(a,b,m,pre,m[curr]+1,end);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &a, vector<int> &b) 
{
    unordered_map<int,int> m;
    
    for(int i=0; i<a.size(); i++)
    {
        m[b[i]] = i;
    }
    
    int x = 0;
    return build(a,b,m,x,0,a.size()-1);
}
