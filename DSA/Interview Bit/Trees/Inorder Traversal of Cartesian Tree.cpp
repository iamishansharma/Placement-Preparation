/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> FindMax(vector<int> &A,int l,int r)
{
    int maxi = INT_MIN;
    int j = 0,i;
    
    for(i=l; i<=r; i++)
    {
        if(maxi <= A[i])
        {
            maxi = A[i];
            j = i;
        }
    }

    vector<int> v(2,0);
    v[1] = maxi;
    v[0] = j;
    
    return v; 
}


TreeNode* Tree(vector<int> &A, int l, int r)
{
    vector<int> v = FindMax(A,l,r);
    
    int mid = v[0];
    
    TreeNode* t = new TreeNode(v[1]);
    
    if(mid-1 >= l)
        t->left=Tree(A,l,mid-1);
    if(mid+1 <= r)
        t->right=Tree(A,mid+1,r);
    
    return t;
}
TreeNode* Solution::buildTree(vector<int> &A) 
{
    return Tree(A,0,A.size()-1);
}