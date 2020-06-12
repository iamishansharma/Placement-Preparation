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
    
    void inOrderT(TreeNode* root, TreeNode** newRoot, TreeNode** curr)
    {
        if(!root)
            return;
        
        inOrderT(root->left, newRoot, curr);
        
        if(*newRoot==NULL) 
            *newRoot=root;
        
        if(*curr) 
            (*curr)->right = root;
        
        *curr = root;
        root->left=NULL;
        
        inOrderT(root->right, newRoot, curr);        
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(!root) 
            return NULL;
        
        TreeNode* curr=NULL;
        TreeNode* newRoot=NULL;
        
        inOrderT(root, &newRoot, &curr);
        
        return newRoot;
    } 
};