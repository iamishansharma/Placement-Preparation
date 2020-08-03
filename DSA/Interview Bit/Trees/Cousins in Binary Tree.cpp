/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* a, int b) 
{
    if(!a || a->val == b) 
        return {};
        
    int level = INT_MAX,curr=0;
    queue<TreeNode *> q;
    q.push(a);
    
    while(!q.empty())
    {
        int x = q.size();
        while(x--)
        {
            TreeNode *temp = q.front();
            q.pop();
            
            if((temp->left && temp->left->val == b) || (temp->right && temp->right->val == b))
                level = curr+1;
            else
            {
                if(temp->left) 
                    q.push(temp->left);
                if(temp->right) 
                    q.push(temp->right);
            }
        }
        curr++;
        if(curr >= level) 
            break;
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
