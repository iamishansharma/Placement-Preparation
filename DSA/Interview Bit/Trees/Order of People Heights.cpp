// https://www.interviewbit.com/problems/order-of-people-heights/

struct Node
{
    int data;
    Node* left;
    Node* right;
    int l;
    
    Node(int d, int size)
    {
        data = d;
        l = size;
        left = right = NULL;
    }
};

Node* insert(Node* root, pair<int, int> &p)
{
    if(!root)
        return new Node(p.first, p.second);
        
    if(p.second<=root->l)
    {
        (root->l)++;
        root->left = insert(root->left, p);
    }
    else
    {
        p.second-=(root->l+1);
        root->right = insert(root->right, p);
    }
    return root;
}

void inorder(Node* root, vector<int> &vec)
{
    if(!root)
        return;
        
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

bool mycomp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) 
{
    vector<pair<int, int> > vec;
    
    for(int i = 0; i<A.size(); i++)
        vec.push_back({A[i], B[i]});
        
    sort(vec.begin(), vec.end(), mycomp);
    
    Node* root = new Node(vec[0].first, vec[0].second);
    
    for(int i = 1; i<vec.size(); i++)
        insert(root, vec[i]);
        
    vector<int> ans;
    
    inorder(root, ans);
    
    return ans;
}