/**

https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) 
{
    vector<vector<int>> v;
    
    if(root == NULL)
    {
        vector<int> temp;
        temp.push_back(-1);
        v.push_back(temp);
        return v;
    }
    
    queue<TreeNode *> q;
    q.push(root);
    
    int i=0;
    
    while(!q.empty())
    {
        int qsize = q.size();
        
        stack<int> s;
        
        vector<int> temp;
        
        while(qsize--)
        {
            TreeNode *t = q.front();
            q.pop();
            
            if(i % 2 == 0)
                temp.push_back(t->val);
            else
                s.push(t->val);
            
            if(t->left)
                q.push(t->left);
            
            if(t->right)
                q.push(t->right);
        }
        i++;
        
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }
        
        v.push_back(temp);
    }
    return v;
}
