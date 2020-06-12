/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
    public:
            void util(Node *root, int &maxval, int depth)
            {
                if(root == NULL)
                    return;
                
                if(depth > maxval)
                    maxval = depth;
                
                for(int i=0; i < root->children.size(); i++)
                    util(root->children[i], maxval, depth + 1);
            }
            int maxDepth(Node* root) 
            {
                if(root == NULL)
                    return 0;
                
                int maxval = 0;
                util(root, maxval, 0);
                return maxval+1;
            }
};