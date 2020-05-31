// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node* helper(int n, int si, int pre[], char preLN[], int &k)
{
    if(si == n)
        return NULL;

    Node* newnode = new Node(pre[si]);
    k++;
    if(preLN[si]=='L')
        return newnode;
    
    newnode->left = helper(n,si+1,pre,preLN,k);
    newnode->right = helper(n,k,pre,preLN,k);
    
    return newnode;
}

Node *constructTree(int n, int pre[], char preLN[])
{
    int k = 0;
    return helper(n,0,pre,preLN,k);
}