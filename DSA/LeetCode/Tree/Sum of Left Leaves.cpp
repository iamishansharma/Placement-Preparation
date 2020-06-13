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
        
        void traversal(TreeNode *root, int &ans, TreeNode *parent)
        {
            if(root == NULL)
                return;
            
            if(parent != NULL && parent->left == root && root->left == NULL && root->right == NULL)
                ans += root->val;
            
            parent = root;
            
            traversal(root->left, ans, parent);
            traversal(root->right, ans, parent);
        }
    
        int sumOfLeftLeaves(TreeNode* root) 
        {
            if(root == NULL)
                return 0;
            
            int ans = 0;
            traversal(root, ans, NULL);
            return ans;
        }
};