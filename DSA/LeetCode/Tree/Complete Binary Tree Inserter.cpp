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
class CBTInserter 
{
    TreeNode *root;
    public:
            CBTInserter(TreeNode* root) 
            {
                this->root = root;
            }
    
            void getParent(TreeNode *root, TreeNode *&parent)
            {
                queue<TreeNode *> q;
                q.push(root);
                
                int flag = 0;
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    
                    while(qsize--)
                    {
                        TreeNode *temp = q.front();
                        q.pop();
                        
                        if(temp->left == NULL || temp->right == NULL)
                        {
                            flag = 1;
                            parent = temp;
                            break;
                        }
                        else
                        {
                            q.push(temp->left);
                            q.push(temp->right);
                        }
                    }
                    if(flag)
                        break;
                }
            }

            int insert(int v) 
            {
                TreeNode *parent = NULL;
                getParent(root, parent);
                
                if(parent->left == NULL)
                    parent->left = new TreeNode(v);
                else
                    parent->right = new TreeNode(v);
                
                return parent->val;
            }

            TreeNode* get_root()
            {
                return root;
            }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */