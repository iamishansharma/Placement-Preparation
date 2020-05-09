#include <bits/stdc++.h>
using namespace std;

typedef struct bst
{
	int data;
	int pos;
	struct bst *left;
	struct bst *right;
}BST;

BST* newNode(int data, int position)
{
	BST *nN = (BST *)malloc(sizeof(BST));
	nN->data = data;
	nN->pos = position;
	nN->left = NULL;
	nN->right = NULL;
	return nN;
}

BST* insertNode(BST *root, int data, int position)
{
	if(root == NULL)
	{
		root = newNode(data,position);
		cout<<root->pos<<endl;
	}
	else if(data<root->data)
	{
		root = insertNode(root->left, data, 2*position);
	}
	else if(data>root->data)
	{
		root = insertNode(root->right, data, 2*position+1);
	}
	return root;
}

BST* minValueNode(BST* node) 
{ 
	if(!node)
		return NULL;

	BST* current = node; 
	while (current && current->left) 
		current = current->left; 
  
	return current; 
} 

BST* deleteNode(BST *root, int key, bool flag)
{
	if (key < root->data) 
		root->left = deleteNode(root->left, key, flag);
	else if (key > root->data) 
		root->right = deleteNode(root->right, key, flag);
	else if(key = root->data)
	{ 
		if(flag)
        {
            cout<<root->pos<<endl;
            flag=false;
        }
        if(!root->left && !root->right)
		{
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            BST *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            BST *temp=root->left;
            free(root);
            return temp;
        }
        BST *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data,flag);
	} 
	return root; 
}

int main()
{
	BST *root = NULL;
	int tc=0;
	char iord;
	int data;
	cin>>tc;
	while(tc--)
	{
		cin>>iord>>data;
		
		if(iord == 'i')
			root = insertNode(root,data,1);
		else
			root = deleteNode(root,data,true);
	}
	return 0;
}