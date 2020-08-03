/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* root)
{
    if(root == NULL)
        return vector<vector<int>> ();
    
    vector<vector<int>> ans;
    
    queue<pair<TreeNode*, int>> q;
    map<int, vector<int>> levelorder;
    
    q.push({root, 0});
    
    while(!q.empty())
    {
        pair<TreeNode*, int> temp;
        temp = q.front();
        q.pop();
        
        levelorder[temp.second].push_back(temp.first->val);
        
        if(temp.first->left != NULL)
            q.push({temp.first->left, temp.second-1});
        
        if(temp.first->right != NULL)
            q.push({temp.first->right, temp.second+1});
        
    }
    
    for(auto i:levelorder)
        ans.push_back(i.second);
    
    return ans;
}
