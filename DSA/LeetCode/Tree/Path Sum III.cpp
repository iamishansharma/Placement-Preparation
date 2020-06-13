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
        void preorder(TreeNode* root,int sum,int &count,vector<int> &v)
        {
            if(root)
            {
                v.push_back(root->val);
                
                preorder(root->left,sum,count,v);
                preorder(root->right,sum,count,v);
                
                int ans = 0;
                
                for(int i=v.size()-1;i>=0;i--)
                {
                    ans += v[i];
                    
                    if(ans == sum)
                        count++;
                }
                v.pop_back();
            }
        }
    
        int pathSum(TreeNode* root, int sum)
        {
            vector<int> v;
            int count = 0;
            preorder(root,sum,count,v);
            return count;
        }
};