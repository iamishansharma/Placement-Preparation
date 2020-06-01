// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



Node* modify(Node *root);

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       //getline(cin, s);
        // int k = stoi(s);
        // getline(cin, s);

        root = modify(root);
        vector<int> v;
        inorder(root, v);
        for(auto i:v)
            cout << i << " ";
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends




/*
Node structure is as follows:
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
// modify the BST and return its root

/*

// USING VECTOR

void populate(Node *root, vector<Node *> &v)
{
    if(root == NULL)
        return;
        
    v.push_back(root);
    
    populate(root->left,v);
    populate(root->right,v);
}

bool sortbyval(Node *n1, Node *n2)
{
    return n1->data > n2->data;
}

Node* modify(Node *root)
{
    if(root == NULL)
        return NULL;
    
    vector<Node *> v;
    
    populate(root, v);
    
    sort(v.begin(), v.end(), sortbyval);
    
    for(int i=1; i<v.size(); i++)
        v[i]->data = v[i]->data + v[i-1]->data;
    
    return root;
}*/

void allgreater(Node *root, int &sum)
{
    if(root == NULL)
        return;
        
    allgreater(root->right, sum);
    
    sum += root->data;
    root->data = sum;
    
    allgreater(root->left, sum);
}

Node* modify(Node *root)
{
    if(root == NULL)
        return NULL;
        
    int sum = 0;
    allgreater(root, sum);
    return root;
}