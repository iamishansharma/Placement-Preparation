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
            /*bool isgood(int node, vector<int> path)
            {
                for(int i=0; i<path.size(); i++)
                    if(path[i] > node)
                        return false;
                
                return true;
            }
    
            void preorder(TreeNode *root, int &ans, vector<int> path)
            {
                if(root == NULL)
                    return;
                
                if(isgood(root->val, path))
                    ans++;
                
                path.push_back(root->val);
                
                preorder(root->left, ans, path);
                preorder(root->right, ans, path);
            }
    
            int goodNodes(TreeNode* root) 
            {
                int ans = 0;
                preorder(root, ans, vector<int> ());
                return ans;
            }*/
    
            void preorder(TreeNode *root, int &ans, int maxval)
            {
                if(root == NULL)
                    return;
                
                if(root->val >= maxval)
                {
                    ans++;
                    maxval = root->val;
                }
                
                preorder(root->left, ans, maxval);
                preorder(root->right, ans, maxval);
            }
    
            int goodNodes(TreeNode* root) 
            {
                int ans = 0;
                preorder(root, ans, INT_MIN);
                return ans;
            }
};