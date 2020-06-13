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
    private:
            unordered_map<int,int> m;
    public:
            void inorder(TreeNode* root, int k, bool &ans)
            {
                if(root == NULL)
                    return;
                
                inorder(root->left, k ,ans);
                
                if(m[k-root->val] == 1)
                    ans = true;
                
                m[root->val] = 1;
                
                inorder(root->right, k ,ans);
            }
    
            bool findTarget(TreeNode* root, int k) 
            {
                if(root == NULL)
                    return false;
                
                m.clear();
                
                bool ans = false;
                inorder(root, k, ans);
                return ans;
            }
};