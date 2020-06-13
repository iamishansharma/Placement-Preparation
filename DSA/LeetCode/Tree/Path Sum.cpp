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
            void solve(TreeNode *root, bool &ans, int sum, int key)
            {
                if(root == NULL)
                    return;
                
                sum += root->val;
                
                if(root->left == NULL && root->right == NULL && sum == key)
                    ans = true;
                
                solve(root->left, ans, sum, key);
                solve(root->right, ans, sum, key);
            }
            bool hasPathSum(TreeNode* root, int sum) 
            {
                if(root == NULL)
                    return false;
                
                bool ans = false;
                solve(root, ans, 0, sum);
                return ans;
            }
};