/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
    public:
            // Encodes a tree to a single string.
            // decode with "*" separator. Ex: 2*1*3 ....etc;
            string serialize(TreeNode* root) 
            {
                string res = "";

                if (root) 
                {
                    res += to_string(root->val) + "*";
                    res += serialize(root->left);
                    res += serialize(root->right);
                }

                return res;
            }

            void buildBST(TreeNode** root, int data) 
            {
                if ((*root) == NULL) 
                    *root = new TreeNode(data);
                else if (data < (*root)->val) 
                    return buildBST(&(*root)->left, data);
                else 
                    return buildBST(&(*root)->right, data);
            }

            // Decodes your encoded data to tree.
            TreeNode* deserialize(string data) 
            {
                TreeNode* root = NULL;

                int found = data.find("*");
                int start = 0;
                
                if (found != string::npos) 
                {
                    while (found != string::npos) 
                    {
                        string val = data.substr(start, found - start);
                        buildBST(&root, stoi(val));
                        start = found + 1;
                        found = data.find("*", start);
                    }
                }

                return root;
            }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));