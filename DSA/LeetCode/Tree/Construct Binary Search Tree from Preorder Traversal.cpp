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
            TreeNode* createNode(int val)
            {
                return new TreeNode(val);
            }
    
            TreeNode* bstFromPreorder(vector<int>& preorder) 
            {
                TreeNode *root = createNode(preorder[0]);
                TreeNode *retRoot=root;
                
                for(vector<int>::iterator it=preorder.begin()+1; it!=preorder.end(); it++)
                    makeBST(root, *it);
                
                return retRoot;
            }
            TreeNode* makeBST(TreeNode *&root, int i)
            {
                if(root)
                {
                    if(root->val>i)
                      root->left = makeBST(root->left,i);
                    
                    if(root->val<i)
                      root->right = makeBST(root->right,i);
                }
                else
                    return createNode(i);
                
                return root;
            }
};