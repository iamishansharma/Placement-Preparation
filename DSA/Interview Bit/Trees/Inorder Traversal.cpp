/**

https://www.interviewbit.com/problems/inorder-traversal/

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    stack<TreeNode*> st;
    vector<int> res;
    
    while(true)
    {
        if(A != NULL)
        {
            st.push(A);
            A = A->left;
        } 
        else 
        {
            if(st.empty())
                break;
                
            A = st.top();
            st.pop();
            res.push_back(A->val);
            A = A->right;
        }
    }

    return res;
}
