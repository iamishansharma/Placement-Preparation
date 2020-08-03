/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) 
{
    stack<TreeNode*> st;
    vector<int> ans;
    
    while(true)
    {
        if(root != NULL)
        {
            st.push(root);
            root = root->left;
        } 
        else 
        {
            if(st.empty())
                break;
                
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }

    return ans;
}
