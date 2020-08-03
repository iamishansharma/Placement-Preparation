// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if(root==NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int inorder[n], preorder[n];
        for(int i=0; i<n; i++)
            cin>> inorder[i];
        for(int i=0; i<n; i++)
            cin>> preorder[i];
        
        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout<< endl;
    }
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int i;

Node *build(int in[],int pre[], int l, int r, int n)
{
    if(l<=r)
    {
        int j;
        
        for(j=0;i<n;j++)
        {
            if(in[j] == pre[i])
                break;
        }
        
        Node *root = new Node(in[j]);
        i++;
        root->left = build(in, pre, l, j-1, n);
        i++;
        root->right = build(in, pre, j+1, r, n);
        
        return root;
    }
    i--;
    return NULL;
}

Node* buildTree(int in[],int pre[], int n)
{
    i = 0;
    return build(in, pre, 0, n-1, n);
}