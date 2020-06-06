/**

https://www.interviewbit.com/problems/recover-binary-search-tree/


 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void morris_traversal(TreeNode* root, vector<int>& soln)
{
    if(root==NULL)
        return;
    
    TreeNode* curr, *prev;
    int prev_val=INT_MIN;
    curr = root;
    
    while(curr!=NULL)
    {
        
        if(curr->left==NULL)
        { // No left subtree, visit node and move to right subtree
            if(curr->val < prev_val)
            {
                soln.push_back(prev_val);
                soln.push_back(curr->val);
            }
            prev_val = curr->val;
            curr = curr->right;
        }
        
        else
        {   // Left subtree present
            prev = curr->left;
            while(prev->right!=NULL and prev->right!=curr)
                prev = prev->right;
            
            if(prev->right==NULL)
            { // Make threaded tree 
                prev->right=curr;
                curr=curr->left;
            }    
            else
            {   // left subtree visited. Visit node and move to right subtre
                if(curr->val < prev_val)
                {
                    soln.push_back(prev_val);
                    soln.push_back(curr->val);
                }
                prev_val = curr->val;
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

vector<int> Solution::recoverTree(TreeNode* A) 
{
    vector<int> soln;
    morris_traversal(A,soln);
    sort(soln.begin(),soln.end());
    
    if(soln.size() == 4)
    {
        soln.erase(soln.begin()+1);
        soln.erase(soln.begin()+1);
    }
    
    return soln;
}
