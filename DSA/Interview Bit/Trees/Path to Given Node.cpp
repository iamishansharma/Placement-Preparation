/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorder(TreeNode *root, int num, vector<int> path, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    path.push_back(root->val);
    
    if(num == root->val)
    {
        ans = path;
        return;
    }
    
    preorder(root->left, num, path, ans);
    preorder(root->right, num, path, ans);
}

vector<int> Solution::solve(TreeNode* root, int num) 
{
    if(root == NULL)
        return {};
    
    vector<int> ans;
    preorder(root, num, vector<int> (), ans);
    return ans;
}
