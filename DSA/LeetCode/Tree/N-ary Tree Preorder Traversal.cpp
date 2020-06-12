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

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        vector<Node*> stk;
        vector<int> result;
        
        Node* cur = root;
        
        while (cur != NULL or !stk.empty()) 
        {
            if (cur == NULL) 
            {
                cur = stk.back(); 
                stk.pop_back();
            }
            
            result.push_back(cur->val);
            
            if (cur->children.size() == 0)
                cur = NULL;
            else 
            {
                stk.insert(stk.end(), cur->children.rbegin(), cur->children.rend()-1);   
                cur = cur->children[0];
            }
        }
		
        return result;       
    }
};