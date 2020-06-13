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
    
            void tree(TreeNode *root, string &s)
            {
                if(root->left == NULL && root->right == NULL)
                {
                    s += to_string(root->val);
                    return;
                }

                s += to_string(root->val);

                if(root->left)
                {
                    s += "(";
                    tree(root->left, s);
                    s += ")";
                }

                if(root->right)
                {
                    if(root->left == NULL)
                    {
                        s += "()";
                    }
                    s += "(";
                    tree(root->right, s);
                    s += ")";
                }
            }

            string tree2str(TreeNode* t) 
            {
                if(t == NULL)
                {
                    return "";
                }
                
                string s;
                tree(t, s);
                return s;
            }
};