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
            pair<int,int> postorder(TreeNode* root, int &ans)
            {
                if(root == NULL) 
                    return {0,0};

                pair<int,int> curr;

                pair<int,int> left = postorder(root->left, ans);
                pair<int,int> right = postorder(root->right, ans);

                int lefttoright = 1 + left.second;
                int righttoleft = 1 + right.first;
                ans = max(ans, max(left.second, right.first));
                curr = {lefttoright, righttoleft};
                
                return curr;
            }


            int longestZigZag(TreeNode* root) 
            {
                int ans = 0;
                postorder(root, ans);
                return ans;
            }
};