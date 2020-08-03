/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root) 
{
    if(root == NULL)
        return {};
        
    vector<int> ans;
    
    stack<TreeNode *> s1, s2;
    s1.push(root);
    
    while(!s1.empty())
    {
        TreeNode *temp = s1.top();
        s1.pop();
        s2.push(temp);
        
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    
    while(!s2.empty())
    {
        ans.push_back(s2.top()->val);
        s2.pop();
    }
    
    return ans;
}
