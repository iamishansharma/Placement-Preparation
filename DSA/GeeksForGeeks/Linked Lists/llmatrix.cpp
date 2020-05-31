// { Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};

void display(Node* head)
{
    Node* Rp;
	Node* Dp = head;
	while (Dp) {
		Rp = Dp;
		while (Rp) {
			cout << Rp->data << " ";
			Rp = Rp->right;
		}
		
		Dp = Dp->down;
	}
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
	    else display(head);
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends


/*structure of the node of the linked list is as

struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *row = (Node *)malloc(sizeof(Node));
    
    Node *newNode = new Node(mat[0][0]);
    head = newNode;
    row = head;
    
    Node *temp = head;
    
    for(int i = 0; i<n; i++)
    {
        if(i != 0)
        {
            Node *nN2 = new Node(mat[i][0]);
            row->down = nN2;
            row = nN2;
            temp = nN2;
        }
        
        for(int j = 1; j<n; j++)
        {
            Node *nN = new Node(mat[i][j]);
            temp->right = nN;
            temp = nN;
        }
    }
    
    return head;
}
