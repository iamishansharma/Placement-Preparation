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
    void util(TreeNode* root, int val, TreeNode* &node)
    {
        if(root == NULL)
            return;
        
        if(root->val == val)
            node = root;
        
        util(root->left, val, node);
        util(root->right, val, node);
    }
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL)
            return NULL;
        
        TreeNode *node = NULL;
        util(root, val, node);
        return node;
    }
};