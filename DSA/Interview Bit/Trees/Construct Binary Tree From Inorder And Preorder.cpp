/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* inpre(vector<int> &in, vector<int> &pre, int &preindex, int start, int end, unordered_map<int,int> &m)
{
    if(start > end)
        return NULL;
    
    TreeNode *temp = new TreeNode(pre[preindex]);
    int i = m[pre[preindex]];
    preindex++;
    
    temp->left = inpre(in, pre, preindex, start, i-1, m);
    temp->right = inpre(in, pre, preindex, i+1, end, m);
    
    return temp;
}

TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) 
{
    unordered_map<int,int> m;
    
    for(int i=0; i<in.size(); i++)
        m[in[i]] = i;
    
    int preindex = 0;
    return inpre(in, pre, preindex, 0, pre.size()-1, m);
}
