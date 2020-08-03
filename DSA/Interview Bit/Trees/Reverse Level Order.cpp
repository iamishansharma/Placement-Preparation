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
    stack<vector<int>> s;
    
    while(!q.empty())
    {
        int qsize = q.size();
        vector<int> arr;
        
        while(qsize--)
        {
            TreeNode *temp = q.front();
            q.pop();
            
            arr.push_back(temp->val);
            
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        s.push(arr);
    }
    
    vector<int> ans;
    
    while(!s.empty())
    {
        vector<int> arr = s.top();
        s.pop();
        
        for(int i=0; i<arr.size(); i++)
            ans.push_back(arr[i]);
    }
    
    return ans;
}
