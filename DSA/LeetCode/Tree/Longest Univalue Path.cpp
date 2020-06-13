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
            int longestUnivaluePath(TreeNode* root) 
            {
                int max = 0;
                helper(root,max);
                return max;
            }

            int maxOneWay(TreeNode* node,int n)
            {
                if(!node)
                    return 0;
                
                if(node->val!=n) 
                    return 0;
                
                else return 1 + max(maxOneWay(node->left,n), maxOneWay(node->right,n));     
            }

            void helper(TreeNode* node, int& m)
            {
                if(node == NULL)
                    return;
                
                int l = maxOneWay(node->left,node->val);
                int r = maxOneWay(node->right,node->val);
                
                m = max(r+l,m);
                
                helper(node->left,m);
                helper(node->right,m);
            }
};