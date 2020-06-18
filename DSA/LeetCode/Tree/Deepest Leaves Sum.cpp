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
            int deepest(TreeNode *root)
            {
                if(root == NULL)
                    return 0;
                
                return 1 + max(deepest(root->left), deepest(root->right));
            }
    
            void getSum(TreeNode *root, int &sum, int level, int deep)
            {
                if(root == NULL)
                    return;
                
                if(level == deep)
                    sum += root->val;
                
                getSum(root->left, sum, level + 1, deep);
                getSum(root->right, sum, level + 1, deep);
            }
    
            int deepestLeavesSum(TreeNode* root) 
            {
                if(root == NULL)
                    return 0;
                
                int deep = deepest(root);
                
                int sum = 0;
                getSum(root, sum, 1, deep);
                return sum;
            }

            /* 

            // Iterative, level order

            int deepestLeavesSum(TreeNode* root) 
            {
                if(root == NULL)
                    return 0;

                queue<TreeNode *> q;
                q.push(root);
                
                int sum = 0;
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    sum = 0;
                    while(qsize--)
                    {
                        TreeNode *temp = q.front();
                        q.pop();
                        
                        sum += temp->val;
                        
                        if(temp->left != NULL)
                            q.push(temp->left);
                        
                        if(temp->right != NULL)
                            q.push(temp->right);
                    }
                }
                
                return sum;
            } */
};