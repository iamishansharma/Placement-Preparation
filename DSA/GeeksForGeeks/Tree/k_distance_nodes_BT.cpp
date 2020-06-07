// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends





/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:

public:

    void findtarget(Node *root, Node *&target, int key)
    {
        if(root == NULL)
            return;
            
        if(root->data == key)
            target = root;
            
        findtarget(root->left, target, key);
        findtarget(root->right, target, key);
    }
    
    void Nodes_Below_Target(Node *root, int k, int currdist, vector<int> &ans)
    {
        if(root == NULL)
            return;
            
        if(currdist == k)
            ans.push_back(root->data);
            
        Nodes_Below_Target(root->left, k, currdist+1, ans);
        Nodes_Below_Target(root->right, k, currdist+1, ans);
    }
    
    int Nodes_Above_Target(Node *root, Node *target, int k, vector<int> &ans)
    {
        if(root == NULL)
            return -1;
            
        if(root == target)
        {
            Nodes_Below_Target(root, k, 0, ans);
            return 0;
        }
            
        int dl = Nodes_Above_Target(root->left, target, k, ans);
        
        if(dl != -1)
        {
            if(dl + 1 == k)
                ans.push_back(root->data);
            else
                Nodes_Below_Target(root->right, k-dl-2, 0, ans); 
               
            return 1 + dl;
        }
        
        int dr = Nodes_Above_Target(root->right, target, k, ans);
        
        if(dr != -1)
        {
            if(dr + 1 == k)
                ans.push_back(root->data);
            else
               Nodes_Below_Target(root->left, k-dr-2, 0, ans); 
               
            return 1 + dr;
        }
        
        return -1;
    }
    
    vector <int> KDistanceNodes(Node* root, int target, int k)
    {
        if(root == NULL)
            return vector<int> ();
            
        Node *tar = NULL;
        
        findtarget(root, tar, target);
        
        if(tar == NULL)
            return vector<int> ();
            
        vector<int> ans;
    
        int temp = Nodes_Above_Target(root, tar, k, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    solver x = solver();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends