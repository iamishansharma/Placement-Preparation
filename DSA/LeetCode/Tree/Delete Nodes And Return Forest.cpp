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
        vector<TreeNode*>  result;
    
    public:
    
        TreeNode* delNodesHelper(TreeNode* root, set<int>& deleteset)
        {
            bool deleted = false;

            if(root == NULL)
                return NULL;
            
            if(deleteset.count(root->val))
            {
                if(root->left && (deleteset.count(root->left->val) == 0))
                     result.push_back(root->left);

                if(root->right && (deleteset.count(root->right->val) == 0))
                    result.push_back(root->right);
                
                deleted = true;
            }

            root->left = delNodesHelper(root->left,deleteset);
            root->right = delNodesHelper(root->right,deleteset);

            if(deleted)
                return NULL;

            return root;

        }
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
        {
            if(root == NULL)
                return result;
            
            set<int> deleteset(to_delete.begin(),to_delete.end());

            if(deleteset.count(root->val) == 0)
                result.push_back(root);

            delNodesHelper(root, deleteset);

            return result;
        }
};