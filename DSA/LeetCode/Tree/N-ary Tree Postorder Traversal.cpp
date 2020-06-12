/*
// Definition for a Node.
class Node 
{
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) 
        {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) 
        {
            val = _val;
            children = _children;
        }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) 
    {
        vector<int> res;
        
        Node* curr = root;
        
        stack<pair<Node*, int>> s;

        while (!s.empty() || curr != NULL) 
        {
            while (curr != NULL) 
            {
                s.push({curr, 0});
                
                if(!curr->children.empty()) 
                    curr = curr->children[0];
                else 
                    curr = NULL;
            }

            s.top().second++;
            
            pair<Node*, int> tmp = s.top();
            
            if(tmp.second >= tmp.first->children.size()) 
            {
                res.push_back(tmp.first->val);
                s.pop();
            } 
            else 
                curr = tmp.first->children[tmp.second];

        }
        return res;
    }
};