#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)        {   cerr << #x << " = " << x <<endl;    }
#define ll              long long int

typedef struct node Node;
struct node
{
    int data;
    Node *right;
    Node *left;
    
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* maketree(vector<int> v, int low, int high)
{
    if(low > high)
        return NULL;
        
    int mid = low + (high - low) / 2;
    
    Node *root = new Node(v[mid]);
    
    root->left = maketree(v, low, mid-1);
    root->right = maketree(v, mid+1, high);
    
    return root;
}

void preorder(Node *root)
{
    if(root == NULL)
        return;
        
    cout<<root->data<<" ";
    
    preorder(root->left);
    preorder(root->right);
}

void solve()
{
    int n=0;
    cin>>n;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    Node *root;
    
    root = maketree(v, 0, n-1);
    
    preorder(root);
    
    cout<<endl;
}

int main()
{
    fastIO;
    
    int tc=0;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}