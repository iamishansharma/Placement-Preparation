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
            int findSecondMinimumValue(TreeNode* root) 
            {        
                int min = (root) ? root->val : -1;
                int nextMin = -1;

                TraverseNodes(root, min, nextMin);
                return nextMin;
            }


            void TraverseNodes(TreeNode* node, int min, int& nextMin) 
            {
                if (!node)
                    return;

                if (node->val > min) 
                {
                     if (nextMin == -1 || node->val < nextMin)
                         nextMin = node->val;                       
                }

                TraverseNodes(node->left, min, nextMin);
                TraverseNodes(node->right, min, nextMin);
            }
};