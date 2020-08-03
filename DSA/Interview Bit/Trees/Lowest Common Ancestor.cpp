/**

https://www.interviewbit.com/problems/least-common-ancestor/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode *root, int num)
{
    if(root == NULL)
        return false;
    
    if(root->val == num)
        return true;
    
    return find(root->left, num) || find(root->right, num);
}
TreeNode *getLCA(TreeNode *root, int num1, int num2)
{
    if(root == NULL)
        return NULL;
    
    if(root->val == num1 || root->val == num2)
        return root;
    
    TreeNode *leftLCA = getLCA(root->left, num1, num2);
    TreeNode *rightLCA = getLCA(root->right, num1, num2);
    
    if(leftLCA != NULL && rightLCA != NULL)
        return root;
    
    return leftLCA == NULL ? rightLCA : leftLCA;
}
int Solution::lca(TreeNode* root, int num1, int num2) 
{
    if(find(root, num1) == false || find(root, num2) == false)
        return -1;
    
    TreeNode *lcanode = NULL;
    lcanode = getLCA(root, num1, num2);
    return lcanode->val;
}

