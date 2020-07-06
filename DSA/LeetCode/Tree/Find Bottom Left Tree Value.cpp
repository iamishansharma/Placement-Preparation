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
            int height(TreeNode *root)
            {
                if(root == NULL)
                    return 0;
                
                return 1 + max(height(root->left), height(root->right));
            }
    
            int findBottomLeftValue(TreeNode* root) 
            {
                int maxdepth = height(root);
                
                int i=1;
                
                queue<TreeNode *> q;
                q.push(root);
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    
                    while(qsize--)
                    {
                        if(i == maxdepth)
                            return q.front()->val;
                        
                        TreeNode *temp = q.front();
                        q.pop();
                        
                        if(temp->left != NULL)
                            q.push(temp->left);
                        
                        if(temp->right != NULL)
                            q.push(temp->right);
                    }
                    i++;
                }
                return 0;
            }
};