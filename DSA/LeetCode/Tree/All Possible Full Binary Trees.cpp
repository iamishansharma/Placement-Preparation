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
            vector<TreeNode*> allPossibleFBT(int N) 
            {
                vector<vector<TreeNode*>> dp(N+1);
                
                dp[1].push_back(new TreeNode(0));
                
                for(int i=3; i<=N; i++)
                {
                    for(int ln=1; ln<=i-1-1; ln+=2)
                    {
                        int rn = i-1-ln;
                        
                        for(TreeNode* lnode: dp[ln])
                        {
                            for(TreeNode* rnode: dp[rn])
                            {
                                TreeNode* root = new TreeNode(0);
                                
                                root->left = lnode;
                                root->right = rnode;
                                
                                dp[i].push_back(root);
                            }
                        }
                    }
                }
                return dp[N];
            }
};