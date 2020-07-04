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
            bool isPseudoPalin(string str)
            {
                vector<char> list; 

                for (int i = 0; i < str.length(); i++) 
                { 
                    auto pos = find(list.begin(), list.end(), str[i]); 

                    if (pos != list.end()) 
                    { 
                        auto posi = find(list.begin(), list.end(),str[i]); 
                        list.erase(posi); 
                    } 
                    else
                        list.push_back(str[i]); 
                } 

                if(str.length() % 2 == 0 && list.empty() || (str.length() % 2 == 1 && list.size() == 1)) 
                    return true; 
                else
                    return false;
            }
    
            void preorder(TreeNode *root, int &ans, string str)
            {
                if(root == NULL)
                    return;
                
                str += root->val + '0';
                
                if(root->left == NULL && root->right == NULL)
                    if(isPseudoPalin(str))
                        ans++;
                
                preorder(root->left, ans, str);
                preorder(root->right, ans, str);
            }
    
            int pseudoPalindromicPaths (TreeNode* root) 
            {
                int ans = 0;
                preorder(root, ans, "");
                return ans;
            }
};