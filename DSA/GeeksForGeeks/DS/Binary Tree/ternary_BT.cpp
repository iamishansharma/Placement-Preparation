// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}// } Driver Code Ends


/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node *rec(Node *root, string str, int *i)
{
    if(*i < str.size())
    {
        if(str[*i] >= 'a' || str[*i] <= 'z')
        {
            root = new Node(str[*i]);
            root->left = root->right = NULL;
            *i += 1;
        }
        
        if(*i < str.size() && str[*i] == '?')
        {  
            *i=*i+1;
            
            root->left = rec(root->left,str,i);
            
            if(*i<str.size() && str[*i]==':')
            { 
                *i=*i+1;
                root->right = rec(root->right,str,i);
            }
        }
    }
    return root;
}

Node *convertExpression(string str,int i)
{
    Node *root = NULL;
    root = rec(root,str, &i);
    return root;
}