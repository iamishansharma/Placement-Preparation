/**

https://www.interviewbit.com/problems/postorder-traversal/


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    vector<int> sol;
    
    if(A==NULL)
        return sol;
        
    stack<TreeNode*> s;
    s.push(A);
    
    while(!s.empty())
    {
        TreeNode* temp = s.top();
        
        if(temp->left==NULL && temp->right==NULL)
        {
            sol.push_back(temp->val);
            s.pop();
        }
        else
        {
            if(temp->right)
                s.push(temp->right);
                
            if(temp->left)
                s.push(temp->left);
                
            temp->left=NULL;
            temp->right=NULL;
        }
    }
    return sol;
}
