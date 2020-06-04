// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int checkSym(TreeNode *root1,TreeNode *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    
    if(root1 == NULL || root2 == NULL)
        return 0;
        
    if(root1->val == root2->val)
        return checkSym(root1->left, root2->right) && checkSym(root1->right, root2->left);
    else
        return 0;
}

int Solution::isSymmetric(TreeNode* root) 
{
    if(root == NULL)
        return 1;
        
    int check = true;
    check = checkSym(root->left, root->right);
    return check;
}
