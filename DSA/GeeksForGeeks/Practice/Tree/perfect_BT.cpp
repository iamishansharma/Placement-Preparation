// { Driver Code Starts
// C program to check whether a given
// Binary Tree is Perfect or not
#include<bits/stdc++.h>
using namespace std;

/*  Tree node structure */
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
// Returns depth of leftmost leaf.
int findADepth(Node *node)
{
   int d = 0;
   while (node != NULL)
   {
      d++;
      node = node->left;
   }
   return d;
}

/* This function tests if a binary tree is perfect
   or not. It basically checks for two things :
   1) All leaves are at same level
   2) All internal nodes have two children */
bool isPerfectRec(struct Node* root, int d, int level );

// Wrapper over isPerfectRec()
bool isPerfect(Node *root)
{
   int d = findADepth(root);
   return isPerfectRec(root, d,0);
}

Node* make_tree()
{
  int n;
  cin>>n;
    
  Node* head=NULL;
  queue <Node*> q;

  for( ; n>0 ; n-- )
  {
    int a,b;
    char c;
    cin>> a >> b >> c;

    if(!head)
    {
      head = new Node(a);
      q.push(head);
    }

    Node* pick = q.front();
    q.pop();

    if(c == 'L')
    {
      pick->left = new Node(b);
      q.push( pick->left );
    }
    
    n--;
    if(!n) break;
    
    cin>> a >> b >> c;
    
    if(c == 'R')
    {
      pick->right = new Node(b);
      q.push( pick->right );
    }
  }
  return head;
}

// Driver Program

int main()
{
    int t,k;
    cin>>t;
    while(t--)
    {
    Node* root = make_tree();
    
    if (isPerfect(root))
        printf("Yes\n");
    else
        printf("No\n");
    }
    return 0;
}
// } Driver Code Ends


/* This function tests if a binary tree is perfect
   or not. It basically checks for two things :
   1) All leaves are at same level
   2) All internal nodes have two children */
bool isPerfectRec(struct Node* root, int d, int level)
{
    // d is depth of BT
    
    if(root == NULL)   
        return level==d;
        
    return isPerfectRec(root->left, d, level+1) && isPerfectRec(root->right, d, level+1);
}
