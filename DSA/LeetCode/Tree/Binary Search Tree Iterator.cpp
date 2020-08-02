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
class BSTIterator 
{
    vector<int> bst;
    int index;
    public:
            void populateVector(TreeNode *root)
            {
                if(root == NULL)
                    return;
                populateVector(root->left);
                bst.push_back(root->val);
                populateVector(root->right);
            }
            BSTIterator(TreeNode* root) 
            {
                index = 0;
                populateVector(root);
            }

            /** @return the next smallest number */
            int next() 
            {
                return bst[index++];
            }

            /** @return whether we have a next smallest number */
            bool hasNext() 
            {
                return !(index-1 == bst.size()-1);
            }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */