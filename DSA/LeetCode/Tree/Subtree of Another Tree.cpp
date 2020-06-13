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
            bool issub(TreeNode* s,TreeNode* t)
            {
                if(s==NULL and t==NULL) 
                    return true;
                if(s==NULL or t==NULL) 
                    return false;
                
                return (s->val == t->val and issub(s->left, t->left) and issub(s->right, t->right));
            }
            bool isSubtree(TreeNode* s, TreeNode* t) 
            {
                if(s==NULL) 
                    return false;
                
                if(issub(s,t)) 
                    return true;
                
                return (isSubtree(s->left,t) or isSubtree(s->right,t));
            }
};