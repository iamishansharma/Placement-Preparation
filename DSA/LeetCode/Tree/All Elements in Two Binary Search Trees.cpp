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
        using Node = TreeNode;
    
        void inorder(Node *root, vector<int>& v) 
        {
            if (root) 
            {
                inorder(root->left, v);
                v.push_back(root->val);
                inorder(root->right, v);
            }
        }
        void merge(vector<int>& a, vector<int>& b, vector<int>& v) 
        {
            int i = 0; int j = 0;
            
            while (i < a.size() && j < b.size()) 
            {
                if (a[i] < b[j]) 
                {
                    v.push_back(a[i]);
                    i++;
                }
                else 
                {
                    v.push_back(b[j]);
                    j++;
                }
            }
            
            while (i < a.size()) 
                v.push_back(a[i++]);
            
            while (j < b.size()) 
                v.push_back(b[j++]);
        }
    
    public:
            vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
            {
                vector<int> v1, v2;
                
                inorder(root1, v1); 
                inorder(root2, v2);
                
                vector<int> v; 
                
                merge(v1, v2, v);
                
                return v;
            }
};