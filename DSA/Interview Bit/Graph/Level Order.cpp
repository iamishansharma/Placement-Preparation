/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    if (root == NULL)
        return vector<vector<int>>();

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int qsize = q.size();
        vector<int> temp;

        while (qsize--)
        {
            TreeNode *front = q.front();
            q.pop();

            temp.push_back(front->val);

            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }

        ans.push_back(temp);
    }

    return ans;
}
