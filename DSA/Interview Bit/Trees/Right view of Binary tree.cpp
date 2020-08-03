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
        return vector<int> ();
    
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    
    while(!q.empty())
    {
        int qsize = q.size();
        ans.push_back(q.back()->val);
        while(qsize--)
        {
            TreeNode *temp = q.front();
            q.pop();
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    
    return ans;
}
