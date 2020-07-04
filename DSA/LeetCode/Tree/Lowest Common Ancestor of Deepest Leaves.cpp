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
            int height(TreeNode* root)
            {
                if(root==NULL)
                    return 0;
                
                return 1+max(height(root->left), height(root->right));
            }
    
            void find(TreeNode*root, TreeNode *&st, TreeNode *&end, int h)
            {
                if(root==NULL)
                    return;
            
                if(h == 1)
                {
                    if(st == NULL)
                        st = root;
                    else
                        end = root;
                }
                
                find(root->left,st,end,h-1);
                find(root->right,st,end,h-1);
            }
    
            TreeNode* lca(TreeNode *root, TreeNode *n1, TreeNode *n2)
            {
                if(root == NULL)
                    return NULL;
                
                if(root == n1 || root == n2)
                    return root;
                
                TreeNode *left_lca = lca(root->left, n1, n2);
                TreeNode *right_lca = lca(root->right, n1, n2);
                
                if(left_lca != NULL && right_lca != NULL)
                    return root;
                
                return left_lca == NULL ? right_lca : left_lca;
            }
    
            TreeNode* lcaDeepestLeaves(TreeNode* root) 
            {
                if(root == NULL)
                    return NULL;
                
                TreeNode *node1 = NULL;
                TreeNode *node2 = NULL;
                
                int maxdepth = height(root);
                
                find(root, node1, node2, maxdepth);
                 
                return lca(root, node1, node2);
            }
};