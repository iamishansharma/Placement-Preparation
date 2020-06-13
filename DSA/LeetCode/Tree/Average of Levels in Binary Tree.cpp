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
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root == NULL)
            return vector<double> ();
        
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        
        while(!q.empty())
        {
            int qsize = q.size();
            int n = qsize;
            double avg = 0;
            
            while(qsize--)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                avg += temp->val;
                
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            
            avg = avg / n;
            ans.push_back(avg);
        }
        
        return ans;
    }
};