/**

https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void rec(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> curr, int currsum)
{
    if(root == NULL)
        return;
        
    curr.push_back(root->val);
    currsum += root->val;
    
    if(root->left == NULL && root->right == NULL && currsum == sum)
        ans.push_back(curr);
    
    rec(root->left, sum, ans, curr, currsum);
    rec(root->right, sum, ans, curr, currsum);
}

vector<vector<int>> Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ans;
    vector<int> curr;
    
    rec(A, B, ans, curr, 0);
    
    return ans;
}
