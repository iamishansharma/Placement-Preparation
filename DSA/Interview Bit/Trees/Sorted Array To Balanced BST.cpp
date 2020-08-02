/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(const vector<int> &num, int low, int high) 
{
    if (low > high)
        return NULL;
    
    if(low == high)
        return new TreeNode(num[low]);

    int mid = (low + high) / 2;
    TreeNode* node = new TreeNode(num[mid]);
    node->left = helper(num, low, mid - 1);
    node->right = helper(num, mid + 1, high);
    return node;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &num) 
{
    if (num.size() == 0) 
        return NULL;
    
    return helper(num, 0, ((int)num.size()) - 1);
}
