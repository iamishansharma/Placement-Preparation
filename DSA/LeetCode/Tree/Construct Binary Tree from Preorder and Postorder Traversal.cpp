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
            TreeNode* buildTree(vector<int>&pre,vector<int>&post,int &preindex,int start,int end)
            {
                if(start>end or preindex>=pre.size())
                    return NULL;
                
                TreeNode* new_head = new TreeNode(pre[preindex++]);
                
                if(preindex == pre.size() or start == end)
                    return new_head;
                
                int i;
                
                for(i=start; i<=end; i++)
                {
                    if(pre[preindex] == post[i])
                        break;
                }
                
                if(i <= end)
                {
                    new_head->left = buildTree(pre,post,preindex,start,i);
                    new_head->right = buildTree(pre,post,preindex,i+1,end-1);
                }
                
                return new_head;
            }
    
            TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
            {
                int preindex = 0 ;
                return buildTree(pre,post,preindex,0,pre.size()-1);
            }
};