// https://www.interviewbit.com/problems/bst-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
queue<int> q;

void buildQueue(TreeNode *root)
{
    if(root == NULL)
        return;
    
    buildQueue(root->left);
    q.push(root->val);
    buildQueue(root->right);
}
BSTIterator::BSTIterator(TreeNode *root) 
{
    buildQueue(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    return(!q.empty());
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    if(!q.empty())
    {
        int x = q.front();
        q.pop();
        return x;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
