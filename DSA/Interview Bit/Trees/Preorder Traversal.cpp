/**

https://www.interviewbit.com/problems/preorder-traversal/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    vector<int> res;
    stack<TreeNode*> s;
    
    while(1)
    {
        if(A)
        {
            res.push_back(A->val);
            s.push(A);
            A=A->left;
        }
        else
        {
            if(s.empty())
                break;
                
            A=s.top()->right;
            s.pop();
        }
    }
    return res;
}
