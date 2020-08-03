// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	
	Node(int x, Node* root){
	    data = x;
	    left = NULL;
	    right = NULL;
	    parent = root;
	}
};

Node* keyNode;
void getNode(Node* root, int key)
{
    if(root==NULL)return;
    getNode(root->left, key);
    // cout<<root->data<<' ';
    if(root->data==key)keyNode = root;
    getNode(root->right, key);
}

Node* findRightSibling(Node* node);

int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1, NULL);
           m[n1] = parent;
           if(root == NULL)root = parent;
        }
        else parent = m[n1];
        child = new Node(n2, parent);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     int key;
     cin>>key;
     getNode(root, key);
     Node* res = findRightSibling(keyNode);
     if(res==NULL)cout<<-1<<endl;
     else cout<<res->data<<endl;
  }
  return 0;
}
// } Driver Code Ends


/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node* left, *right, *parent;
};
*/
// function should return return the node of the 
// right sibling to the provided node
Node* findRightSibling(Node* node)
{
    if(node == NULL)
        return NULL;
    
    Node *root = node;
    
    while(root->parent != NULL)
        root = root->parent;
    
    Node *temp = root;
    
    queue<Node*> Q;
    
    Q.push(temp);
    Q.push(NULL);
    
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        
        if(Q.empty())
            return NULL;
            
        if(temp == node)
            return Q.front();
            
        if(temp == NULL)
        {
            Q.push(temp);
            continue;
        }
        
        if(temp->left != NULL)
            Q.push(temp->left);
        if(temp->right != NULL)
            Q.push(temp->right);
    }
}