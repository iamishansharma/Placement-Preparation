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
class FindElements 
{
    unordered_set<int> lookup;
    
            void recover(TreeNode* root, int val) 
            {        
                root->val = val;

                if (root->left) 
                {
                    int leftVal = 2 * val + 1;
                    lookup.insert(leftVal);
                    recover(root->left, leftVal);
                }

                if (root->right) 
                {
                    int rightVal = 2 * val + 2;
                    lookup.insert(rightVal);
                    recover(root->right, rightVal);
                }
            }
    
    public:
    
            FindElements(TreeNode* root) 
            {
                if (root) {
                    lookup.insert(0);
                    recover(root, 0);   
                }
            }

            bool find(int target) 
            {
                return lookup.count(target);
            }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */