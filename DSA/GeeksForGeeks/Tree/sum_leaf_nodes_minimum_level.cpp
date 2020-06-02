// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
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


int minLeafSum(Node* root);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<minLeafSum(root)<<endl;
  }
  return 0;
}
// Contributed by: Harshit Sidhwa
// } Driver Code Ends


//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
int minLeafSum(Node* root)
{
    if(!root) return 0;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        int sum=0;
        int flag=0;
        
        while(size--)
        {
            Node* temp=q.front(); 
            q.pop();
            
            if(!temp->left and !temp->right)
            {
                flag = 1;
                sum += temp->data;
            }
            
            if(temp->left) 
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
        }
        if(flag)
        {
            return sum;
        }
    }
}