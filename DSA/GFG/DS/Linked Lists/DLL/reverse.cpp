// { Driver Code Starts




//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}


Node *addNode(Node *head, int data)
{
    if(head==NULL)
    head=newNode(data);
    else
    {
        Node * temp=head;
        Node * prev=head;
        while(temp->next)
            {
                prev=temp;
                temp=temp->next;
                
            }
        temp->next=newNode(data);
        prev=temp;
        temp=temp->next;
        temp->prev=prev;
    }
    
    return head;
}



void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


 // } Driver Code Ends







#include <stack>
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

// Stack Implementation

/*Node* reverseDLL(Node * head)
{
    if(head == NULL)
        return head;
        
    Node *temp = head;
    
    stack<int> s;
    
    while(temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while(!s.empty())
    {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    
    return head;
}*/

// Using pointers

Node* reverseDLL(Node *head)
{
    Node *temp = NULL;  
    Node *current = head; 

    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  

    if(temp != NULL)  
        head = temp->prev;
        
    return head;
}


// { Driver Code Starts.

int main() {
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      Node *head=NULL;
      for(int i=0;i<n;i++)
      {
          int x;
          cin>>x;
          head=addNode(head,x);
      }
      head=reverseDLL(head);
      
      
      if(verify(head))
      displayList(head);
      else
      cout<<"Your pointers are not correctly connected";
 
      cout<<endl;
  }
  return 0;
}

  // } Driver Code Ends