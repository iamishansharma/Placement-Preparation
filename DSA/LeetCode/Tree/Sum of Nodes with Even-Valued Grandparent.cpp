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
            void helper(TreeNode *root, int &sum, TreeNode *parent, TreeNode *gp)
            {
                if(root == NULL)
                    return;
                
                if(parent == NULL)
                    parent = root;
                else
                {
                    if(gp == NULL)
                    {
                        gp = parent;
                        parent = root;
                    }
                    else
                    {
                        if(gp->val % 2 == 0)
                            sum += root->val;
                        
                        gp = parent;
                        parent = root;
                    }
                }
                
                helper(root->left, sum, parent, gp);
                helper(root->right, sum, parent, gp);
            }
    
            int sumEvenGrandparent(TreeNode* root) 
            {
                if(root == NULL)
                    return 0;
                
                int sum = 0;
                helper(root, sum, NULL, NULL);
                return sum;
            }
};