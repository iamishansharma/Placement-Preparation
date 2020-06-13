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
        void solve(TreeNode*node, vector<int>&v)
        {
            if(node == NULL) 
                return;
            
            solve(node->left,v);
            
            v.push_back(node->val);
            
            solve(node->right,v);
            
            return;
        }
    
        int getMinimumDifference(TreeNode* root) 
        {
            vector<int>v;
            solve(root,v);
            
            int ans = INT_MAX;
            
            for(int i=0; i<v.size()-1; i++)
            {
                int dif = abs(v[i]-v[i+1]);
                ans = min(ans,dif);
            }
            return ans;
        }
};