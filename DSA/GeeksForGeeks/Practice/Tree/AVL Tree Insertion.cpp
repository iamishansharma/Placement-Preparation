// { Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
    if(!n) return 1;
    if( n->data <= lower || n->data >= upper ) return 0;
    return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
    if(!n) return pair<int,bool> (0,1);

    pair<int,bool> l = isBalanced(n->left);
    pair<int,bool> r = isBalanced(n->right);

    if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

    return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
    if( !isBST(root, INT_MIN, INT_MAX) )
        cout<< "BST voilated, inorder traversal : ";

    else if ( ! isBalanced(root).second )
        cout<< "Unbalanced BST, inorder traversal : ";

    else return 1;
    return 0;
}

void printInorder(Node* n)
{
    if(!n) return;
    printInorder(n->left);
    cout<< n->data << " ";
    printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
    int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

/*You are required to complete this method */
// A utility function to get height  
// of the tree  
int height(Node *N)  
{  
    if (N == NULL)  
        return 0;
        
    return N->height;  
}  
  
// A utility function to get maximum 
// of two integers  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
/* Helper function that allocates a  
   new node with the given key and  
   NULL left and right pointers. */
Node* newNode(int key)  
{  
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
  
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;
        
    return height(N->left) - height(N->right);  
}  
  
Node* insertToAVL(Node* node, int key)  
{  
    /* 1. Perform the normal BST rotation */
    if (node == NULL)  
        return(newNode(key));  
  
    if (key < node->data)  
        node->left = insertToAVL(node->left, key);  
    else if (key > node->data)  
        node->right = insertToAVL(node->right, key);  
    else // Equal keys not allowed  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));  
  
    /* 3. Get the balance factor of this  
        ancestor node to check whether  
        this node became unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, 
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && key < node->left->data)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->data)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}