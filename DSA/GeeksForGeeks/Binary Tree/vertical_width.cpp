// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// your task is to complete this functionh
// function should return the width of the tree
int verticalWidth(Node* root);




 // } Driver Code Ends


//User function Template for C++
/*Structure of node of binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// your task is to complete this functionh
// function should return the width of the tree
void calminmax(Node *root, int &min, int &max, int width)
{
    if(root == NULL)
        return;
        
    if(width < min)
        min = width;
        
    if(width > max)
        max = width;
    
    calminmax(root->left, min, max, width-1);
    calminmax(root->right, min, max, width+1);
}

int verticalWidth(Node* root)
{
    if(root == NULL)
        return 0;
    
    int min = 0;
    int max = 0;
    
    calminmax(root, min, max, 0);
    
    return max - min + 1;
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        
        cout << verticalWidth(root) << "\n";
    }


    return 0;
}
  // } Driver Code Ends