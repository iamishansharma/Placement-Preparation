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
    void heightParent(TreeNode *root, int key, int level, int &h, TreeNode *&parent)
    {
        if(root == NULL)
            return;
        
        if(root->val == key)
            h = level;
        
        if(root->left != NULL && root->left->val == key)
            parent = root;
        
        if(root->right != NULL && root->right->val == key)
            parent = root;
        
        heightParent(root->left, key, level + 1, h, parent);
        heightParent(root->right, key, level + 1, h, parent);
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        if(root == NULL)
            return false;
        
        int h1 = 0;
        TreeNode *p1 = NULL;
        heightParent(root, x, 0, h1, p1);
        int h2 = 0;
        TreeNode *p2 = NULL;
        heightParent(root, y, 0, h2, p2);
        
        if(h1 == h2 && p1 != p2)
            return true;
        else
            return false;
    }
};