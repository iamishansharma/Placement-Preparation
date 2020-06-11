// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
int level(Node *root, int a, int curr)
{
    if(root == NULL)
        return 0;
        
    if(root->data == a)
        return curr;
        
    return max(level(root->left, a, curr + 1), level(root->right, a, curr + 1));
}
void getNodeParent(Node *root, int a, Node *&nodeparent)
{
    if(root == NULL)
        return;
    
    if(root->left != NULL && root->left->data == a)
        nodeparent = root;
    
    if(root->right != NULL && root->right->data == a)
         nodeparent = root;
        
    getNodeParent(root->left, a, nodeparent);
    getNodeParent(root->right, a, nodeparent);
}

bool isSibling(Node *root, int a, int b)
{
    Node *anodeparent = NULL;
    Node *bnodeparent = NULL;
    
    getNodeParent(root, a, anodeparent);
    getNodeParent(root, b, bnodeparent);
    
    if(anodeparent == bnodeparent)
        return true;
    else
        return false;
}

bool isCousins(Node *root, int a, int b)
{
    if(root == NULL)
        return false;
    
    if(level(root, a, 0) == level(root, b, 0) && isSibling(root, a, b) == 0)
        return true;
    else
        return false;
}