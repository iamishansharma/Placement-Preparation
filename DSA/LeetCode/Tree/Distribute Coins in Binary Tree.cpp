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
            int sum = 0;
    
            int dfs(TreeNode* root)
            {
                if(!root)
                    return 0;
                
                int extra = root->val + dfs(root->left) + dfs(root->right) - 1;
                
                sum += abs(extra);
                
                return extra;
            }
            int distributeCoins(TreeNode* root) 
            {
                dfs(root);  
                return sum;
            }
};