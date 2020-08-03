/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) 
{
    if(root == NULL)
        return {};
    
    queue<TreeNode *> q;
    q.push(root);
    
    vector<int> ans;
    
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        
        while(temp)
        {
            ans.push_back(temp->val);
            
            if(temp->left) 
                q.push(temp->left);
                
            temp = temp->right;
        }
        
    }
    return ans;
}
