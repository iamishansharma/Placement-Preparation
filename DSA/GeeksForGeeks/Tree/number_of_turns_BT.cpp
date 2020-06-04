// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
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

int NumberOFTurns(struct Node* root, int first, int second);

 // } Driver Code Ends





//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
// function should return the number of turns required to go from first node to second node
typedef struct Node Node;

Node *LCA(Node *root,int first,int second)
{
    if(root==NULL) return NULL;
    if((root->data)==first) return root;
    if((root->data)==second) return root;
    
    Node* left = LCA(root->left,first,second);
    Node* right = LCA(root->right,first,second);
    
    if(left && right) return root;
    return left ? left:right;
}

void turns(Node *root,int data,int &max,int count=0,int left=0,int right=0)
{
    if(root==NULL) 
        return;
    
    if((root->data)==data)
        if(max<count)
            max=count;
    
    int temp = (right ? count+1 : count);
    
    turns(root->left,data,max,temp,1,0);
    
    temp = (left ? count+1 : count);
    
    turns(root->right,data,max,temp,0,1);
}

int dist(Node *root,int data)
{
    if(root==NULL)
        return 0;
        
    int max=0;
    turns(root,data,max);
    return max;
}

int NumberOFTurns(Node* root, int first, int second)
{
    if(root==NULL)
        return 0;
    
    Node *lca = LCA(root,first,second);
    
    if((lca->data)==(first))
        return dist(lca,second);
    else if((lca->data)==(second))
        return dist(lca,first);
        
    return dist(lca,first) + dist(lca,second) + 1;
}

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends