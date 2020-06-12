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
        void util(TreeNode* root, int l, int r, int &sum)
        {
            if(root == NULL)
                return;
            util(root->left, l, r, sum);
            if(root->val >= l && root->val <= r)
                sum += root->val;
            util(root->right, l, r, sum);    
        }
        int rangeSumBST(TreeNode* root, int L, int R) 
        {
            if(root == NULL)
                return 0;
            
            int sum = 0;
            util(root, L, R, sum);
            return sum;
        }
};