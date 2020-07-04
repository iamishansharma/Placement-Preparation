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
            vector<vector<int>> levelOrder(Node* root) 
            {
                if(root == NULL)
                    return vector<vector<int>> ();
                
                vector<vector<int>> ans;
                
                queue<Node *> q;
                q.push(root);
                
                while(!q.empty())
                {
                    int qsize = q.size();
                    
                    vector<int> toi;
                    
                    while(qsize--)
                    {
                        Node *temp = q.front();
                        q.pop();
                        
                        toi.push_back(temp->val);
                        
                        for(int i=0; i<temp->children.size(); i++)
                            q.push(temp->children[i]);
                    }
                    ans.push_back(toi);
                }
                
                return ans;
            }
};