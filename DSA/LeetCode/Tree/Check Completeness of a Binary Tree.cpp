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
            bool isCompleteTree(TreeNode* root) 
            {
                if (root == NULL) 
                    return true;
        
                queue<TreeNode*> q;
                q.push(root);
                int sz = 0;
                TreeNode* n = NULL;
                bool nullFound = false;

                while (!q.empty()) 
                {
                    sz = q.size();            

                    for (int i = 0; i < sz; i++) 
                    {
                        n = q.front();
                        q.pop();
                        
                        if(n == NULL) 
                        {
                            nullFound = true;
                            continue;
                        }

                        if((nullFound && n != NULL) || (n->left == NULL && n->right != NULL))
                            return false;

                        q.push(n->left);
                        q.push(n->right);
                    }                        
                }
                return true;
            }
};