// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
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
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

// This function should returns sum of
// maximum sum path from any node in
// a tree rooted with given root.
int rec(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = rec(root->left, ans);
    int right = rec(root->right, ans);

    int max1 = max(max(left, right) + root->data, root->data);
    int max2 = max(max1, left + right + root->data);

    ans = max(max2, ans);

    return max1;
}

int findMaxSum(Node *root)
{
    int ans = INT_MIN;

    if (root == NULL)
        return ans;

    rec(root, ans);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << findMaxSum(root) << "\n";
    }

    return 0;
} // } Driver Code Ends