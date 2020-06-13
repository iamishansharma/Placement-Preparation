/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
            vector<vector<int>> levelOrderBottom(TreeNode* root) 
            {
                if(root == NULL)
                    return vector<vector<int>> ();
                
                vector<vector<int>> ans;
                stack<vector<int>> st;
                queue<TreeNode*> q;
                q.push(root);
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    
                    vector<int> tempv;
                    
                    while(qsize--)
                    {
                        TreeNode *temp = q.front();
                        q.pop();
                        
                        tempv.push_back(temp->val);
                        
                        if(temp->left != NULL)
                            q.push(temp->left);
                        
                        if(temp->right != NULL)
                            q.push(temp->right);
                    }
                    
                    st.push(tempv);
                }
                
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                
                return ans;
            }
};