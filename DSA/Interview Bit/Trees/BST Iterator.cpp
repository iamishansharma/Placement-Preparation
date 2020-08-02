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

/* 

    Space: O(h) not O(n)
ß
*/

stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) 
{
    while(!s.empty())
        s.pop();
        
    TreeNode *c=root;
    while(c)
        s.push(c),c=c->left;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    if(!s.empty())
        return true;
    else
        return false;
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    if(!s.empty())
    {
        int v = s.top()->val;
        TreeNode *c = s.top()->right;
        s.pop();
        
        while(c)
            s.push(c),c=c->left;
        
        return v;
    }
    else
        return -1;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
