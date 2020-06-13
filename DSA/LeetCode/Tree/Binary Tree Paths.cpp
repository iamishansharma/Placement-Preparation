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
            void traversal(TreeNode *root, vector<string> &ans, string s)
            {
                if(root == NULL)
                    return;
                
                if(root->left == NULL && root->right == NULL)
                {
                    s += to_string(root->val);
                    ans.push_back(s);
                }
                else
                    s += to_string(root->val) + "->";
                
                traversal(root->left, ans, s);
                traversal(root->right, ans, s);
            }
    
            vector<string> binaryTreePaths(TreeNode* root) 
            {
                if(root == NULL)
                    return vector<string> ();
                
                vector<string> ans;
                traversal(root, ans, "");
                return ans;
            }
};