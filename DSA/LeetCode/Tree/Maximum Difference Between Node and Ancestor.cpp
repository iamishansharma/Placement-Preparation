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
        void preorder(TreeNode *root, int &maxval, int mintillnow, int maxtillnow)
        {
            if(root == NULL)
                return;
            
            maxtillnow = max(maxtillnow, root->val);
            mintillnow = min(mintillnow, root->val);
            
            maxval = max(maxval, abs(maxtillnow-mintillnow));
            
            preorder(root->left, maxval, mintillnow, maxtillnow);
            preorder(root->right, maxval, mintillnow, maxtillnow);
        }
    
        int maxAncestorDiff(TreeNode* root) 
        {
            int maxval = INT_MIN;
            preorder(root, maxval, INT_MAX, INT_MIN);
            return maxval;
        }
};