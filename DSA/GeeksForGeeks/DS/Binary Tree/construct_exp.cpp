// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* make(char postfix[],int& end)
{
    et* root = new et(postfix[end--]);
    
    if(root->value=='+' || root->value=='*' || root->value=='-' || root->value=='/' || root->value=='^')
    {
        root->right = make(postfix,end);
        root->left = make(postfix,end);
    }
    
    return root;
}
et* constructTree(char postfix[])
{
    int end = strlen(postfix)-1;
    return make(postfix,end);
}

