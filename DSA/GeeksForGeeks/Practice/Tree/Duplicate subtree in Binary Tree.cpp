// { Driver Code Starts
#include <bits/stdc++.h>
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

struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
        root= new Node(data);
        return root;
    }

    else if(root->data<data)
    root->right=insert(root->right,data);

    else if(root->data>data)
    root->left=insert(root->left,data);

  return root;
}







struct Node* insertString(struct Node* root,string s, int *j)
{

    if((*j)>=s.length())
    return NULL;

            if(s[*j]=='(')
            (*j)++;


           if(s[*j]!='('&&s[*j]!=')'){
               
               char n=0;
               n = s[*j];
             (*j)++;

            root=insert(root,n);

            //cout<<"root->data="<<root->data<<endl;

           // (*j)++;

            if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
              //cout<<"root->right=NULL\n";
              return root;
            }

           }

             if(s[*j]=='(')
            (*j)++;

            if(s[*j]==')'){
              //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
            root->left=NULL;
            }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
            root->left=insertString(root->left,s,j);
              }

//cout<<"right\n";

              while(s[*j]==')')
            (*j)++;

            if(s[*j]=='(')
            (*j)++;

            if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL\n";
            root->right=NULL;
            (*j)++;
            }
            else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
            }
return root;
}

void print(struct Node* root)
{

    if(root==NULL)
        return;


    print (root->left);
    cout<<root->data<<endl;
    print(root->right);

}
bool dupSub(Node *root);

int main() {
  //code
  int i,j,k,T ,level;
  char s[500];

     cin>>T;

     for(i=0;i<T;i++)
     {
       // cin>>level;

        cin>>s;

        int j=0;

        struct Node* root=NULL;

        root=insertString(root,s,&j);
     
        cout<<dupSub(root)<<endl;

    

     }




  return 0;
}

// } Driver Code Ends


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
string inorder(Node* root)
{
    string s="";
    
    if(!root)
        return s;
        
    string ls = inorder(root->left);
    string rs = inorder(root->right);
    s = ls + root->data + rs;
    return s;
}

bool dup(Node *root, set<string> &st)
{
    string s="";
    
    if(!root)
        return false;

    bool left=dup(root->left,st);
    bool right=dup(root->right,st);
    
    string ls=inorder(root->left);
    string rs=inorder(root->right);
    
    s = ls + root->data + rs;
    
    if(st.find(s)!=st.end() || left || right)
        return true;
    else
        if(s.length() >= 2)
            st.insert(s);
            
    return false;
}
bool dupSub(Node* root)
{
    set<string> st;
    return dup(root,st);
}