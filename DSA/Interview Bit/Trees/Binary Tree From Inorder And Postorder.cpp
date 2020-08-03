/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode * inpost(vector<int> &in, vector<int> &post, int start, int end, int &postorder, unordered_map<int,int> &m)
{
    if(start > end)
        return NULL;
    
    TreeNode *temp = new TreeNode(post[postorder]);
    int i = m[post[postorder]];
    postorder--;
    
    temp->left = inpost(in, post, start, i-1, postorder, m);
    temp->right = inpost(in, post, i+1, end, postorder, m);
    
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) 
{
    unordered_map<int,int> m;
    
    for(int i=0; i<in.size(); i++)
        m[in[i]] = i;
    
    int postorder = post.size()-1;
    return inpost(in, post, 0, in.size()-1, postorder, m);
}
